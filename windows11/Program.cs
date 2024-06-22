using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Management;
using System.Windows.Forms;
using NAudio.CoreAudioApi;

namespace windows11
{
    internal class Program
    {
        static void memory(System.Management.ManagementObject mo)
        {
            decimal totalVisibleMemorySize = decimal.Parse(mo["TotalVisibleMemorySize"].ToString());
            decimal freePhysicalMemory = decimal.Parse(mo["FreePhysicalMemory"].ToString());
            decimal usePhysicalMemory = totalVisibleMemorySize - freePhysicalMemory;

            Console.WriteLine("usePhysicalMemory: {0:N0}KiB, {1:0.0}GiB", usePhysicalMemory, usePhysicalMemory / 1024 / 1024);
            Console.WriteLine("freePhysicalMemory: {0:N0}KiB, {1:0.0}GiB", freePhysicalMemory, freePhysicalMemory / 1024 / 1024);
            Console.WriteLine("totalVisibleMemorySize: {0:N0}KiB, {1:0.0}GiB", totalVisibleMemorySize, totalVisibleMemorySize / 1024 / 1024);
            Console.WriteLine("usage: {0:0}%", usePhysicalMemory / totalVisibleMemorySize * 100);
        }

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

            // システム全体の音量設定値を取得
            // デフォルトの音声出力デバイスを取得
            //var enumerator = new MMDeviceEnumerator();
            //var device = enumerator.GetDefaultAudioEndpoint(DataFlow.Render, Role.Console);
            // システムの音量設定値を0～1の範囲で取得
            //float systemVolume = device.AudioEndpointVolume.MasterVolumeLevelScalar;
            // 音量をパーセンテージ(0～100)に変換して表示
            //Console.WriteLine($"System volume: {systemVolume * 100:0}%");

            // CPU 使用率を取得
            /*
            // カテゴリ名・カウンタ名・インスタンス名を指定してPerformanceCounterのインスタンスを作成
            var pc = new PerformanceCounter("Processor Information", "% Processor Utility", "_Total");
            for (; ; )
            {
                // カウンタの値を取得して、値を0.0～1.0の範囲にする
                var percent = pc.NextValue() / 100.0f;

                // パーセント値として表示
                Console.WriteLine("{0,8:P2}", percent);

                Thread.Sleep(1000);
            }
            */

            // メモリ使用量を取得
            /*
            // WMIインスタンスを取得
            using (ManagementClass mc = new System.Management.ManagementClass("Win32_OperatingSystem"))
            using (ManagementObjectCollection ins = mc.GetInstances())
            {
                foreach (System.Management.ManagementObject mo in ins)
                {
                    memory(mo); // ローカルメソッド呼び出し
                    mo.Dispose();
                    break;
                }
            }
            */
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
