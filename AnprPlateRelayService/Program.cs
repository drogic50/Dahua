using System.ServiceProcess;

namespace AnprPlateRelayService
{
    static class Program
    {
        static void Main()
        {
            ServiceBase[] ServicesToRun;
            ServicesToRun = new ServiceBase[]
            {
                new PlateRelayService()
            };
            ServiceBase.Run(ServicesToRun);
        }
    }
}