using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Net.Sockets;
using System.ServiceProcess;
using System.Text;
using System.Threading;
using MySql.Data.MySqlClient;

namespace AnprPlateRelayService
{
    public partial class PlateRelayService : ServiceBase
    {
        private Thread workerThread;
        private bool running = false;
        private IniFile ini;
        private string mysqlConnStr;
        private string[] cameraIPs;
        private int[] cameraPorts;
        private string[] cameraUsers;
        private string[] cameraPwds;
        private string winDevHost;
        private int winDevPort;

        public PlateRelayService()
        {
            // InitializeComponent(); // 

        }

        protected override void OnStart(string[] args)
        {
            ini = new IniFile(AppDomain.CurrentDomain.BaseDirectory + "anpr.ini");
            mysqlConnStr = $"Server={ini.Read("Server", "MySQL")};Port={ini.Read("Port", "MySQL")};Database={ini.Read("Database", "MySQL")};Uid={ini.Read("Username", "MySQL")};Pwd={ini.Read("Password", "MySQL")};";
            cameraIPs = new[] { ini.Read("IP", "Camera1"), ini.Read("IP", "Camera2") };
            cameraPorts = new[] { int.Parse(ini.Read("Port", "Camera1")), int.Parse(ini.Read("Port", "Camera2")) };
            cameraUsers = new[] { ini.Read("Username", "Camera1"), ini.Read("Username", "Camera2") };
            cameraPwds = new[] { ini.Read("Password", "Camera1"), ini.Read("Password", "Camera2") };
            winDevHost = ini.Read("WinDevHost", "Socket");
            winDevPort = int.Parse(ini.Read("WinDevPort", "Socket"));

            running = true;
            workerThread = new Thread(ServiceLoop) { IsBackground = true };
            workerThread.Start();

            DahuaSdk.PlateRecognized += OnPlateRecognized;
            DahuaSdk.RegisterPlateCallback();
            // Login both cameras
            for (int i = 0; i < cameraIPs.Length; i++)
                DahuaSdk.Login(cameraIPs[i], cameraPorts[i], cameraUsers[i], cameraPwds[i]);
        }

        protected override void OnStop()
        {
            running = false;
            DahuaSdk.PlateRecognized -= OnPlateRecognized;
        }

        private void ServiceLoop()
        {
            while (running) Thread.Sleep(1000);
        }

        private void OnPlateRecognized(object sender, PlateRecognizedEventArgs e)
        {
            byte[] processedImage = ProcessImage(e.ImageData);

            var newArgs = new PlateRecognizedEventArgs
            {
                CameraIp = e.CameraIp,
                PlateNumber = e.PlateNumber,
                Timestamp = e.Timestamp,
                ImageData = processedImage
            };
            SaveToMySql(newArgs);
            SendPlateToWinDev(newArgs);
        }

        private byte[] ProcessImage(byte[] imageData)
        {
            if (imageData == null || imageData.Length == 0)
                return new byte[0];

            const int maxRawSize = 3 * 1024 * 1024; // 3MB
            const int targetSize = 2 * 1024 * 1024; // 2MB

            if (imageData.Length <= maxRawSize)
                return imageData;

            try
            {
                using (var msIn = new MemoryStream(imageData))
                using (var img = Image.FromStream(msIn))
                {
                    long quality = 90L;
                    byte[] jpegData = null;

                    do
                    {
                        using (var msOut = new MemoryStream())
                        {
                            var encoder = GetJpegEncoder();
                            var encoderParams = new System.Drawing.Imaging.EncoderParameters(1);
                            encoderParams.Param[0] = new System.Drawing.Imaging.EncoderParameter(System.Drawing.Imaging.Encoder.Quality, quality);
                            img.Save(msOut, encoder, encoderParams);
                            jpegData = msOut.ToArray();

                            if (jpegData.Length <= targetSize || quality <= 10)
                                break;
                        }
                        quality -= 10;
                    } while (true);

                    return jpegData;
                }
            }
            catch
            {
                // If anything fails, fallback to original or empty
                return new byte[0];
            }
        }

        private static ImageCodecInfo GetJpegEncoder()
        {
            ImageCodecInfo[] codecs = ImageCodecInfo.GetImageDecoders();
            foreach (var c in codecs)
                if (c.FormatID == ImageFormat.Jpeg.Guid)
                    return c;
            return null;
        }

        private void SaveToMySql(PlateRecognizedEventArgs e)
        {
            try
            {
                using (var conn = new MySqlConnection(mysqlConnStr))
                {
                    conn.Open();
                    var cmd = new MySqlCommand("INSERT INTO tblCameraLog (cameraip, platenumber, timestamp, imagedata) VALUES (@ip, @plate, @ts, @img)", conn);
                    cmd.Parameters.AddWithValue("@ip", e.CameraIp);
                    cmd.Parameters.AddWithValue("@plate", e.PlateNumber);
                    cmd.Parameters.AddWithValue("@ts", e.Timestamp);
                    cmd.Parameters.AddWithValue("@img", e.ImageData ?? new byte[0]);
                    cmd.ExecuteNonQuery();
                }
            }
            catch
            {
                // Optionally log or handle error
            }
        }

        private void SendPlateToWinDev(PlateRecognizedEventArgs e)
        {
            try
            {
                using (var client = new TcpClient())
                {
                    client.Connect(winDevHost, winDevPort);
                    using (var stream = client.GetStream())
                    using (var writer = new StreamWriter(stream, new UTF8Encoding(false)) { AutoFlush = true })
                    {
                        // [CameraIP]\n[PlateNumber]\n[Date]\n[Time]\n[Length]\n[BINARY_IMAGE]
                        writer.WriteLine(e.CameraIp ?? "");
                        writer.WriteLine(e.PlateNumber ?? "");
                        writer.WriteLine(e.Timestamp.ToString("dd.MM.yyyy"));
                        writer.WriteLine(e.Timestamp.ToString("HH:mm"));
                        byte[] img = e.ImageData ?? new byte[0];
                        writer.WriteLine(img.Length.ToString());
                        writer.Flush();
                        stream.Write(img, 0, img.Length);
                        stream.Flush();
                    }
                }
            }
            catch
            {
                // Optionally log or handle error
            }
        }
    }
}