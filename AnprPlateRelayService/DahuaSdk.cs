using System;

namespace AnprPlateRelayService
{
    public static class DahuaSdk
    {
        public static event EventHandler<PlateRecognizedEventArgs> PlateRecognized;

        // Simulated login logic for two cameras
        public static bool Login(string ip, int port, string user, string pass) => true;
        public static void RegisterPlateCallback() { /* In real app, register actual callback here */ }
        public static void SimulatePlate(string cameraIp, string plate, DateTime ts, byte[] img)
        {
            PlateRecognized?.Invoke(null, new PlateRecognizedEventArgs
            {
                CameraIp = cameraIp,
                PlateNumber = plate,
                Timestamp = ts,
                ImageData = img
            });
        }
    }
}