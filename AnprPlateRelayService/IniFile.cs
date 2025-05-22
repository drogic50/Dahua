using System.Runtime.InteropServices;
using System.Text;

namespace AnprPlateRelayService
{
    public class IniFile
    {
        private readonly string _path;
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(string section, string key, string def, StringBuilder retVal, int size, string filePath);

        public IniFile(string path) { _path = path; }

        public string Read(string key, string section)
        {
            var sb = new StringBuilder(255);
            GetPrivateProfileString(section, key, "", sb, 255, _path);
            return sb.ToString();
        }
    }
}