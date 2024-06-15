using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace windows11
{
    internal class Program
    {
        [DllImport("user32.dll")]
        private static extern bool SetForegroundWindow(IntPtr hWnd);
        static void Main(string[] args)
        {
            // 現在実行中のすべてのプロセスを取得
            Process[] processlist = Process.GetProcesses();
            Array.Sort(processlist, new ProcComparator());
            Process amazonMusic = null;

            foreach (Process p in processlist)
            {
                if (p.MainWindowTitle == "Amazon Music")
                {
                    // プロセス名とIDを出力
                    Console.WriteLine("プロセス名: {0} ID: {1} Title: {2}", p.ProcessName, p.Id, p.MainWindowTitle);
                    amazonMusic = p;
                    break;
                }
            }

            // Space Key を送り、Play/Pause する
            if (amazonMusic != null)
            {
                SetForegroundWindow(amazonMusic.MainWindowHandle);
                System.Windows.Forms.SendKeys.SendWait(" ");
            }

            // Volumer を経由してボリュームを操作するには
            // p.ProcessName == "Volumer" でマッチする
            // 音量上げる: System.Windows.Forms.SendKeys.SendWait("%{F12}");
            // 音量下げる: System.Windows.Forms.SendKeys.SendWait("%{F11}");

            // ScreenInStyle を経由して EV2785 のソースを操作するには
            // p.ProcessName == "ScreenInStyle" でマッチする
            // DisplayPort: System.Windows.Forms.SendKeys.SendWait("^+1");
            // HDMI1: System.Windows.Forms.SendKeys.SendWait("^+2");
        }
    }

    // プロセス名でソート ... for Array.Sort
    public class ProcComparator : IComparer<Process>
    {
        public int Compare(Process p, Process q)
        {
            return p.ProcessName.CompareTo(q.ProcessName);
        }
    }
}
