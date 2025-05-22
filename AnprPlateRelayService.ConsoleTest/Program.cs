using System;
using System.IO;
using System.Net.Sockets;
using System.Text;

namespace AnprPlateRelayService.ConsoleTest
{
    class Program
    {
        static void Main(string[] args)
        {
            // These values can be changed for your test scenario
            string windevHost = "127.0.0.1";
            int windevPort = 9013;
            string cameraIp = "192.168.1.101";
            string plateNumber = "ZG123ČĆŽ";
            DateTime timestamp = DateTime.Now;
            string date = timestamp.ToString("dd.MM.yyyy");
            string time = timestamp.ToString("HH:mm");

            // For testing, create a small "fake" JPEG (or load a test image if you want)
            byte[] imageData = Encoding.UTF8.GetBytes("FAKEJPEGDATA");

            Console.WriteLine($"Connecting to {windevHost}:{windevPort} ...");
            try
            {
                using (var client = new TcpClient())
                {
                    client.Connect(windevHost, windevPort);
                    using (var stream = client.GetStream())
                    using (var writer = new StreamWriter(stream, new UTF8Encoding(false)) { AutoFlush = true })
                    {
                        writer.WriteLine(cameraIp);
                        writer.WriteLine(plateNumber);
                        writer.WriteLine(date);
                        writer.WriteLine(time);
                        writer.WriteLine(imageData.Length.ToString());
                        writer.Flush();
                        stream.Write(imageData, 0, imageData.Length);
                        stream.Flush();

                        // Wait for a response "1" from the server (WinDev)
                        using (var reader = new StreamReader(stream, Encoding.UTF8, false, 1024, true))
                        {
                            // Read up to 1kB or until the server closes the connection
                            string response = reader.ReadLine();
                            if (response == "1")
                                Console.WriteLine("Received expected response: 1");
                            else
                                Console.WriteLine("Unexpected or no response from WinDev. Response: " + (response ?? "<null>"));
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error sending test data: {ex.Message}");
            }
        }
    }
}