using NateJin.Vector2;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Graphs
{
    class Matrix
    {
        static int minTime(int[][] roads, int[] machines)
        {
            bool[] seenMachines = new bool[machines.Length];

            Dictionary<MyVec2Int, int> roadDic = new Dictionary<MyVec2Int, int>();
            Dictionary<int, bool> seenMarchin = new Dictionary<int, bool>();
            Dictionary<int, bool> seenCity = new Dictionary<int, bool>();
            Dictionary<int, List<int>> connectCity = new Dictionary<int, List<int>>();

            for (int i = 0; i < machines.Length; i++)
            {
                seenMarchin.Add(machines[i], false);
            }


            for (int i = 0; i < roads.Length; i++)
            {
                if (connectCity.TryAdd(roads[i][0], new List<int>(){ roads[i][1] }))
                    connectCity[roads[i][0]].Add(roads[i][1]);
                if (connectCity.TryAdd(roads[i][1], new List<int>() { roads[i][0] }))
                    connectCity[roads[i][1]].Add(roads[i][0]);

                roadDic.Add(new MyVec2Int(roads[i][1], roads[i][0]), roads[i][2]);
                roadDic.Add(new MyVec2Int(roads[i][0], roads[i][1]), roads[i][2]);
            }

            int totalTime = 0;

            foreach (var item in seenMarchin)
            {
                if (item.Value) continue;
                seenMarchin[item.Key] = true;
                Queue<int> targetCity = new Queue<int>();

                foreach (var city in connectCity[item.Key])
                {
                    targetCity.Enqueue(city);
                }
                int minValue = 10000000;
                MyVec2Int minBridge = new MyVec2Int(-1, -1);
                while (targetCity.Count > 0)
                {
                    //connectCity[targetCity.Dequeue()];
                }

            }
            return 2;
        }

        //연결된도시의 도로 최소값

        //기계의 존재하는지 확인

        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nk[0]);

            int k = Convert.ToInt32(nk[1]);

            int[][] roads = new int[n - 1][];

            try
            {
                for (int i = 0; i < n - 1; i++)
                {
                    roads[i] = Array.ConvertAll(Console.ReadLine().Split(' '), roadsTemp => Convert.ToInt32(roadsTemp));
                }
            }
            catch (Exception)
            {
                for (int i = 0; i < n - 1; i++)
                {
                    roads[i] = Array.ConvertAll(Console.ReadLine().Split(' '), roadsTemp => Convert.ToInt32(roadsTemp));
                }

            }


            int[] machines = new int[k];

            for (int i = 0; i < k; i++)
            {
                int machinesItem = Convert.ToInt32(Console.ReadLine());
                machines[i] = machinesItem;
            }

            int result = minTime(roads, machines);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
