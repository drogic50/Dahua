using System;

namespace AnprPlateRelayService
{
    public class PlateRecognizedEventArgs : EventArgs
    {
        public string CameraIp { get; set; }
        public string PlateNumber { get; set; }
        public DateTime Timestamp { get; set; }
        public byte[] ImageData { get; set; }
    }
}