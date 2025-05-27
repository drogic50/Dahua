using System;
using System.Drawing;
using System.IO;
using System.Net.Sockets;
using System.Text;
using System.Windows.Forms;
using MySql.Data.MySqlClient;
using AnprPlateRelayService;
using System.Drawing.Imaging;

namespace AnprPlateRelayService.ConsoleTest
{
    public class ManualEntryForm : Form
    {
        TextBox txtPlate, txtPlateColor, txtPlateType, txtVehicleType, txtVehicleColor, txtVehicleSize, txtLane, txtDeviceAddress;
        TextBox txtBboxLeft, txtBboxTop, txtBboxWidth, txtBboxHeight;
        TextBox txtFileIndex, txtFileCount, txtGroupId, txtCameraIp;
        DateTimePicker dtEventTime;
        Button btnSubmit, btnLoadImage;
        Label lblStatus;
        PictureBox picSnapshot;

        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // ManualEntryForm
            // 
            this.AutoScroll = true;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(284, 361);
            this.Name = "ManualEntryForm";
            this.Load += new System.EventHandler(this.ManualEntryForm_Load);
            this.ResumeLayout(false);

        }

        private void ManualEntryForm_Load(object sender, EventArgs e)
        {

        }

        byte[] snapshotJpg;

        string mysqlConnStr = "Server=localhost;Port=3306;Database=anprdb;Uid=anpruser;Pwd=anprpassword;";
        string winDevHost = "127.0.0.1";
        int winDevPort = 9013;

        public ManualEntryForm()
        {
            // Optionally load these from INI at startup
            try
            {
                var ini = new IniFile("C:\\My Projects\\modbus_test\\.NET\\WrapperService\\AnprPlateRelayService\\bin\\x64\\Debug\\net472\\anpr.ini");
                winDevHost = ini.Read("WinDevHost", "Socket");
                int.TryParse(ini.Read("WinDevPort", "Socket"), out winDevPort);
                mysqlConnStr = $"Server={ini.Read("Server", "MySQL")};Port={ini.Read("Port", "MySQL")};Database={ini.Read("Database", "MySQL")};Uid={ini.Read("Username", "MySQL")};Pwd={ini.Read("Password", "MySQL")};";
              
            }
            catch { }

            this.Text = "Manual Plate Event Entry";
            this.Size = new Size(500, 900);
            this.FormBorderStyle = FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;

            int y = 15, dy = 32;

            Controls.Add(MakeLabel("Plate Number:", 20, y));      txtPlate = MakeTextBox(150, y);         y += dy;
            Controls.Add(txtPlate);

            Controls.Add(MakeLabel("Plate Color:", 20, y));       txtPlateColor = MakeTextBox(150, y);    y += dy;
            Controls.Add(txtPlateColor);

            Controls.Add(MakeLabel("Plate Type:", 20, y));        txtPlateType = MakeTextBox(150, y);     y += dy;
            Controls.Add(txtPlateType);

            Controls.Add(MakeLabel("Vehicle Type:", 20, y));      txtVehicleType = MakeTextBox(150, y);   y += dy;
            Controls.Add(txtVehicleType);

            Controls.Add(MakeLabel("Vehicle Color:", 20, y));     txtVehicleColor = MakeTextBox(150, y);  y += dy;
            Controls.Add(txtVehicleColor);

            Controls.Add(MakeLabel("Vehicle Size:", 20, y));      txtVehicleSize = MakeTextBox(150, y);   y += dy;
            Controls.Add(txtVehicleSize);

            Controls.Add(MakeLabel("Lane:", 20, y));              txtLane = MakeTextBox(150, y);          y += dy;
            Controls.Add(txtLane);

            Controls.Add(MakeLabel("Device Address:", 20, y));    txtDeviceAddress = MakeTextBox(150, y); y += dy;
            Controls.Add(txtDeviceAddress);

            Controls.Add(MakeLabel("Bounding Box Left:", 20, y)); txtBboxLeft = MakeTextBox(150, y);      y += dy;
            Controls.Add(txtBboxLeft);

            Controls.Add(MakeLabel("Bounding Box Top:", 20, y));  txtBboxTop = MakeTextBox(150, y);       y += dy;
            Controls.Add(txtBboxTop);

            Controls.Add(MakeLabel("Bounding Box Width:", 20, y));txtBboxWidth = MakeTextBox(150, y);     y += dy;
            Controls.Add(txtBboxWidth);

            Controls.Add(MakeLabel("Bounding Box Height:", 20, y));txtBboxHeight = MakeTextBox(150, y);   y += dy;
            Controls.Add(txtBboxHeight);

            Controls.Add(MakeLabel("Event Time:", 20, y));        dtEventTime = new DateTimePicker { Left = 150, Top = y, Width = 200, Format = DateTimePickerFormat.Custom, CustomFormat = "yyyy-MM-dd HH:mm:ss" }; y += dy;
            Controls.Add(dtEventTime);

            Controls.Add(MakeLabel("File Index:", 20, y));        txtFileIndex = MakeTextBox(150, y);     y += dy;
            Controls.Add(txtFileIndex);

            Controls.Add(MakeLabel("File Count:", 20, y));        txtFileCount = MakeTextBox(150, y);     y += dy;
            Controls.Add(txtFileCount);

            Controls.Add(MakeLabel("Group Id:", 20, y));          txtGroupId = MakeTextBox(150, y);       y += dy;
            Controls.Add(txtGroupId);

            Controls.Add(MakeLabel("Camera IP:", 20, y));         txtCameraIp = MakeTextBox(150, y);      y += dy;
            txtCameraIp.Text = "192.168.1.101";
            Controls.Add(txtCameraIp);

            Controls.Add(MakeLabel("Snapshot Picture:", 20, y));  btnLoadImage = new Button { Text = "Load Image...", Left = 150, Top = y, Width = 120 }; y += dy;
            btnLoadImage.Click += BtnLoadImage_Click;
            Controls.Add(btnLoadImage);

            picSnapshot = new PictureBox { Left = 150, Top = y, Width = 200, Height = 150, BorderStyle = BorderStyle.FixedSingle, SizeMode = PictureBoxSizeMode.Zoom }; y += 160;
            Controls.Add(picSnapshot);

            btnSubmit = new Button { Text = "Submit", Left = 150, Top = y, Width = 100 };
            btnSubmit.Click += BtnSubmit_Click;
            Controls.Add(btnSubmit);

            lblStatus = new Label { Left = 20, Top = y + 40, Width = 400, Height = 30, ForeColor = Color.DarkBlue };
            Controls.Add(lblStatus);
        }
        
        private Label MakeLabel(string text, int x, int y) =>
            new Label { Text = text, Left = x, Top = y + 4, Width = 120, TextAlign = ContentAlignment.MiddleRight };
        private TextBox MakeTextBox(int x, int y) =>
            new TextBox { Left = x, Top = y, Width = 200 };

        private void BtnLoadImage_Click(object sender, EventArgs e)
        {
            using (var ofd = new OpenFileDialog())
            {
                ofd.Filter = "JPEG files (*.jpg;*.jpeg)|*.jpg;*.jpeg|All files (*.*)|*.*";
                if (ofd.ShowDialog() == DialogResult.OK)
                {
                    var origBytes = File.ReadAllBytes(ofd.FileName);
                    snapshotJpg = ProcessImage(origBytes);
                    using (var ms = new MemoryStream(snapshotJpg))
                    {
                        picSnapshot.Image = Image.FromStream(ms);
                    }
                }
            }
        }

        /// <summary>
        /// If the image is >2MB, recompress to JPEG with reduced quality until <=2MB.
        /// </summary>
        private byte[] ProcessImage(byte[] imageData)
        {
            if (imageData == null || imageData.Length == 0)
                return new byte[0];

            const int maxSize = 2 * 1024 * 1024; // 2MB

            if (imageData.Length <= maxSize)
                return imageData;

            try
            {
                using (var msIn = new MemoryStream(imageData))
                using (var img = Image.FromStream(msIn))
                {
                    long quality = 90L;
                    byte[] outBytes = null;

                    while (quality >= 10)
                    {
                        using (var msOut = new MemoryStream())
                        {
                            var encoder = GetEncoder(ImageFormat.Jpeg);
                            var eps = new EncoderParameters(1);
                            eps.Param[0] = new EncoderParameter(System.Drawing.Imaging.Encoder.Quality, quality);
                            img.Save(msOut, encoder, eps);
                            outBytes = msOut.ToArray();
                            if (outBytes.Length <= maxSize)
                                return outBytes;
                        }
                        quality -= 10;
                    }
                    // If all fails, return the smallest version
                    return outBytes;
                }
            }
            catch
            {
                // On exception, return original
                return imageData;
            }
        }

        private ImageCodecInfo GetEncoder(ImageFormat format)
        {
            ImageCodecInfo[] codecs = ImageCodecInfo.GetImageDecoders();
            foreach (ImageCodecInfo codec in codecs)
            {
                if (codec.FormatID == format.Guid)
                    return codec;
            }
            return null;
        }
        public void wait(int milliseconds)
        {
            var timer1 = new System.Windows.Forms.Timer();
            if (milliseconds == 0 || milliseconds < 0) return;

            // Console.WriteLine("start wait timer");
            timer1.Interval = milliseconds;
            timer1.Enabled = true;
            timer1.Start();

            timer1.Tick += (s, e) =>
            {
                timer1.Enabled = false;
                timer1.Stop();
                // Console.WriteLine("stop wait timer");
            };

            while (timer1.Enabled)
            {
                Application.DoEvents();
            }
        }

        private void BtnSubmit_Click(object sender, EventArgs e)
        {
            try
            {
                var plate = txtPlate.Text.Trim();
                var plateColor = txtPlateColor.Text.Trim();
                var plateType = txtPlateType.Text.Trim();
                var vehicleType = txtVehicleType.Text.Trim();
                var vehicleColor = txtVehicleColor.Text.Trim();
                int vehicleSize = ParseInt(txtVehicleSize.Text);
                int lane = ParseInt(txtLane.Text);
                var deviceAddress = txtDeviceAddress.Text.Trim();
                int bboxLeft = ParseInt(txtBboxLeft.Text);
                int bboxTop = ParseInt(txtBboxTop.Text);
                int bboxWidth = ParseInt(txtBboxWidth.Text);
                int bboxHeight = ParseInt(txtBboxHeight.Text);
                DateTime eventTime = dtEventTime.Value;
                int fileIndex = ParseInt(txtFileIndex.Text);
                int fileCount = ParseInt(txtFileCount.Text);
                int groupId = ParseInt(txtGroupId.Text);
                var cameraIp = txtCameraIp.Text.Trim();

                bool dbOk = SaveToMySql(cameraIp, plate, eventTime, plateColor, plateType, vehicleType, vehicleColor, vehicleSize, lane, deviceAddress, bboxLeft, bboxTop, bboxWidth, bboxHeight, fileIndex, fileCount, groupId, snapshotJpg);
                bool socketOk = SendPlateToWinDev(cameraIp, plate, eventTime, plateColor, plateType, vehicleType, vehicleColor, vehicleSize, lane, deviceAddress, bboxLeft, bboxTop, bboxWidth, bboxHeight, fileIndex, fileCount, groupId);
                lblStatus.Text = mysqlConnStr;
                lblStatus.Visible = true;
                wait(3000);

                if (dbOk && socketOk)
                    lblStatus.Text = "Saved and sent successfully!";
                else if (!dbOk && !socketOk)
                    lblStatus.Text = "Both MySQL and Windev send failed!";
                else if (!dbOk)
                    lblStatus.Text = "Windev OK, MySQL failed!";
                else
                    lblStatus.Text = "MySQL OK, Windev failed!";
            }
            catch (Exception ex)
            {
                lblStatus.Text = "Error: " + ex.Message;
            }
        }

        private int ParseInt(string s)
        {
            int val;
            int.TryParse(s, out val);
            return val;
        }

        private bool SaveToMySql(string camIp, string plate, DateTime ts, string plateColor, string plateType, string vehicleType, string vehicleColor, int vehicleSize, int lane, string deviceAddress, int bboxLeft, int bboxTop, int bboxWidth, int bboxHeight, int fileIndex, int fileCount, int groupId, byte[] snapshotJpg)
        {
            try
            {
                using (var conn = new MySqlConnection(mysqlConnStr))
                {
                    conn.Open();
                    var cmd = new MySqlCommand(@"INSERT INTO tblCameraLog 
                        (cameraip, platenumber, timestamp, vehicletype, vehicleCATEGORY, IMAGEDATA)
                        VALUES (@cam, @plate, @ts, @vtype,  @vsize, @snapshot)", conn);
                    cmd.Parameters.AddWithValue("@cam", camIp);
                    cmd.Parameters.AddWithValue("@plate", plate);
                    cmd.Parameters.AddWithValue("@ts", ts);
                  
                    cmd.Parameters.AddWithValue("@vtype", vehicleType);
                    
                    cmd.Parameters.AddWithValue("@vsize", vehicleSize);
                    
                    cmd.Parameters.Add("@snapshot", MySqlDbType.LongBlob).Value = snapshotJpg ?? new byte[0];
                    cmd.ExecuteNonQuery();
                }
                return true;
            }
            catch (Exception ex)
            {
                lblStatus.Text = "DB error: " + ex.Message;
                wait(3000);
                return false;
            }
        }

        private bool SendPlateToWinDev(string camIp, string plate, DateTime ts, string plateColor, string plateType, string vehicleType, string vehicleColor, int vehicleSize, int lane, string deviceAddress, int bboxLeft, int bboxTop, int bboxWidth, int bboxHeight, int fileIndex, int fileCount, int groupId)
        {
            string msg = $"{camIp}|{plate}|{ts:yyyy-MM-dd HH:mm:ss}|{plateColor}|{plateType}|{vehicleType}|{vehicleColor}|{vehicleSize}|{lane}|{deviceAddress}|{bboxLeft}|{bboxTop}|{bboxWidth}|{bboxHeight}|{fileIndex}|{fileCount}|{groupId}\n";
            int retryCount = 3, timeout = 3;
            try
            {
                try { int.TryParse(new IniFile("anpr.ini").Read("RetryCount", "Socket"), out retryCount); } catch {}
                try { int.TryParse(new IniFile("anpr.ini").Read("ResponseTimeout", "Socket"), out timeout); } catch {}
                if (retryCount <= 0) retryCount = 3;
                if (timeout <= 0) timeout = 3;

                bool result = SocketHelper.SendAndWaitForOK(winDevHost, winDevPort, msg, retryCount, timeout, err => lblStatus.Text = err);
                return result;
            }
            catch (Exception ex)
            {
                lblStatus.Text = "Socket error: " + ex.Message;
                return false;
            }
        }
    }
}