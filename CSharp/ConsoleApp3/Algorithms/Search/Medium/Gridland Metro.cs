using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Search.Medium
{
    class Gridland_Metro
    {
        // Complete the gridlandMetro function below.
        static long gridlandMetro(int n, int m, int k, int[][] track)
        {
            Dictionary<int, List<int>> tempDic = new Dictionary<int, List<int>>();
            for (int i = 0; i < k; i++)
            {
                int start = track[i][1];
                int end = track[i][2];
                if (!tempDic.ContainsKey(track[i][0]))
                {
                    tempDic.Add(track[i][0], new List<int>());
                }
                while (start <= end)
                {
                    if (!tempDic[track[i][0]].Contains(start))
                    {
                        tempDic[track[i][0]].Add(start);
                    }
                    start++;
                }
            }
            long count = (long)n * (long)m;
            foreach (var item in tempDic)
            {
                var arr = item.Value.OrderBy(x => x).Distinct().ToArray();
                for (int i = 0; i < arr.Length; i++)
                {
                    Console.WriteLine(arr[i]);
                }
                count-= arr.Length;
            }
            return count;
        }

        static int gridlandMetro1(int n, int m, int k, int[][] track)
        {
            bool[,] tracked = new bool[n,m];
            for (int i = 0; i < k; i++)
            {
                int r = track[i][0];
                int start = track[i][1];
                int end = track[i][2];

                for (int j = start - 1; j < end ; j++)
                {
                    if (!tracked[r, j])
                    {
                        tracked[r, j] = true;
                    }
                }
            }
            int count = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!tracked[i, j])
                    {
                        count++;
                    }
                    
                }
            }
            return count;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nmk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nmk[0]);

            int m = Convert.ToInt32(nmk[1]);

            int k = Convert.ToInt32(nmk[2]);

            int[][] track = new int[k][];

            for (int i = 0; i < k; i++)
            {
                track[i] = Array.ConvertAll(Console.ReadLine().Split(' '), trackTemp => Convert.ToInt32(trackTemp));
            }

            long result = gridlandMetro(n, m, k, track);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
