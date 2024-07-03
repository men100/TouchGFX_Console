using System.IO.Ports;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Management;
using System.Timers;
using System.Windows.Forms;
using NAudio.CoreAudioApi;

namespace windows11
{
    internal class Program
    {
        static SerialPort? serialPort;
        static byte volume = 0;
        static Process? amazonMusicProcess;
        static Process? volumerProcess;


        struct Packet
        {
            public byte size;
            public byte version;
            public byte result;
            public byte volume;
        }

        // 構造体をbyte[]に変換
        static byte[] StructToBytes<T>(T str) where T : struct
        {
            int size = Marshal.SizeOf(str);
            byte[] arr = new byte[size];

            IntPtr ptr = Marshal.AllocHGlobal(size);
            Marshal.StructureToPtr(str, ptr, true);
            Marshal.Copy(ptr, arr, 0, size);
            Marshal.FreeHGlobal(ptr);
            return arr;
        }

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

        // 音量上げる
        static void VolumeUp()
        {
            if (volumerProcess != null)
            {
                SetForegroundWindow(volumerProcess.MainWindowHandle);
                // Alt + F12
                System.Windows.Forms.SendKeys.SendWait("%{F12}");
            }
        }

        // 音量下げる
        static void VolumeDown()
        {
            if (volumerProcess != null)
            {
                SetForegroundWindow(volumerProcess.MainWindowHandle);
                // Alt + F11
                System.Windows.Forms.SendKeys.SendWait("%{F11}");
            }
        }

        // データ受信イベントハンドラ
        static void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            string data = sp.ReadExisting();  // 受信データを読み込む
            Console.WriteLine("Received: " + data);

            Packet packet = new Packet();
            packet.size = 4;
            packet.version = 0;
            packet.result = 0;
            packet.volume = volume;

            byte[] packetBytes = StructToBytes(packet);
            if (serialPort != null)
            {
                switch (data)
                {
                    case "INFO":
                        serialPort.Write(packetBytes, 0, packetBytes.Length);
                        break;

                    case "VLUP":
                        VolumeUp();
                        break;

                    case "VLDN":
                        VolumeDown();
                        break;

                    default:
                        Console.WriteLine("Invalid Command. So do nothing");
                        break;
                }
            }
        }

        // タイマーイベントハンドラ
        private static void OnTimedEvent(Object? source, ElapsedEventArgs e)
        {
            // 1秒ごとに実行したい処理をここに記述
            Console.WriteLine("The Elapsed event was raised at {0:HH:mm:ss.fff}", e.SignalTime);

            // システム全体の音量設定値を取得
            {
                // デフォルトの音声出力デバイスを取得
                var enumerator = new MMDeviceEnumerator();
                var device = enumerator.GetDefaultAudioEndpoint(DataFlow.Render, Role.Console);

                // システムの音量設定値を0～1の範囲で取得
                float systemVolume = device.AudioEndpointVolume.MasterVolumeLevelScalar;

                // 音量をパーセンテージ(0～100)に変換して表示
                Console.WriteLine($"System volume: {systemVolume * 100:0}%");

                volume = (byte)(systemVolume * 100);
            }
        }

        [DllImport("user32.dll")]
        private static extern bool SetForegroundWindow(IntPtr hWnd);
        static void Main(string[] args)
        {
            // 1秒間隔のタイマーを作成
            System.Timers.Timer timer = new System.Timers.Timer(1000);
            timer.Elapsed += OnTimedEvent;
            timer.Start();

            // STLink の Port を探す
            string portName = "";
            string stLinkDescription = "STMicroelectronics STLink Virtual COM Port";
            ManagementObjectSearcher searcher = new ManagementObjectSearcher("SELECT * FROM Win32_PnPEntity WHERE Caption LIKE '%(COM%'");
            foreach (ManagementObject obj in searcher.Get())
            {
                string caption = obj["Caption"].ToString().Split('(', ')')[1];
                string description = obj["Description"].ToString();

                if (description == stLinkDescription)
                {
                    portName = caption;
                    Console.WriteLine($"Found! Port: {portName}");
                    break;
                }
            }

            // 操作に必要なプロセスハンドルを取得しておく
            {
                // 現在実行中のすべてのプロセスを取得
                Process[] processlist = Process.GetProcesses();
                Array.Sort(processlist, new ProcComparator());

                foreach (Process p in processlist)
                {
                    if (p.MainWindowTitle == "Amazon Music")
                    {
                        // プロセス名とIDを出力
                        Console.WriteLine("プロセス名: {0} ID: {1} Title: {2}", p.ProcessName, p.Id, p.MainWindowTitle);
                        amazonMusicProcess = p;
                    }
                    if (p.ProcessName == "Volumer")
                    {
                        // プロセス名とIDを出力
                        Console.WriteLine("プロセス名: {0} ID: {1}", p.ProcessName, p.Id);
                        volumerProcess = p;
                    }
                }
            }

            if (portName != null)
            {
                serialPort = new SerialPort();

                // シリアルポートの設定
                serialPort.PortName = portName;     // 使用するCOMポート名
                serialPort.BaudRate = 115200;       // ボーレート
                serialPort.Parity = Parity.None;    // パリティビット
                serialPort.DataBits = 8;            // データビット
                serialPort.StopBits = StopBits.One; // ストップビット

                serialPort.Open();  // シリアルポートを開く

                // データ受信イベントハンドラを登録
                serialPort.ReceivedBytesThreshold = 4;
                serialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

                Console.WriteLine("Press any key to exit...");
                Console.ReadKey();

                serialPort.Close();  // シリアルポートを閉じる
            }

            timer.Stop();
            timer.Dispose();

            /*
            // Space Key を送り、Play/Pause する
            if (amazonMusic != null)
            {
                SetForegroundWindow(amazonMusic.MainWindowHandle);
                System.Windows.Forms.SendKeys.SendWait(" ");
            }
            */

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

            // GPU 使用率を取得
            /*
            var category = new PerformanceCounterCategory("GPU Engine");
            var counterNames = category.GetInstanceNames();
            var gpuCounters = counterNames
                .Where(counterName => counterName.EndsWith("engtype_3D"))
                .SelectMany(counterName => category.GetCounters(counterName))
                .Where(counter => counter.CounterName.Equals("Utilization Percentage"))
                .ToList();

            for (; ; )
            {
                float result = 0.0f;
                foreach (PerformanceCounter gpuCounter in gpuCounters)
                {
                    float tmpValue = gpuCounter.NextValue();
                    result += tmpValue;
                }
                Console.WriteLine($"GPU Usage: {result:0}%");

                Thread.Sleep(1000);
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
