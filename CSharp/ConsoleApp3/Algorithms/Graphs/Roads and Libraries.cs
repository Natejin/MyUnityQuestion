using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Graphs
{
    class Roads_and_Libraries
    {
        static bool[] visited;
        static int[,] adjCities;
        static long roadsAndLibraries(int n, int c_lib, int c_road, int[][] cities)
        {
            if (c_lib <= c_road)
            {
                return c_lib * n;
            }
            else {
                //bool[] visited = new bool[n];
                //int[,] adjCities = new int[n, n];
                int numberRoad = cities.Length;
                adjCities = new int[cities.Length, cities.Length];
                for (int i = 0; i < numberRoad; i++)
                {
                    int c1 = cities[i][0];
                    int c2 = cities[i][1];

                    Console.WriteLine("{0} {1}", c1, c2);
                    adjCities[c1 - 1, c1 - 1] = c1;
                    adjCities[c2 - 1, c2 - 1] = c2;

                    
                }
            }


            return 0;
        }

        private static void dfs(int  city)
        {
            visited[city] = true;
            for (int i = 0; i < adjCities.GetLength(0); i++)
            {
                if (!visited[i])
                {
                    //total += roadCost;
                    dfs(i);
                }
            }
        }


        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int q = Convert.ToInt32(Console.ReadLine());

            for (int qItr = 0; qItr < q; qItr++)
            {
                string[] nmC_libC_road = Console.ReadLine().Split(' ');

                int n = Convert.ToInt32(nmC_libC_road[0]);

                int m = Convert.ToInt32(nmC_libC_road[1]);

                int c_lib = Convert.ToInt32(nmC_libC_road[2]);

                int c_road = Convert.ToInt32(nmC_libC_road[3]);

                int[][] cities = new int[m][];

                for (int i = 0; i < m; i++)
                {
                    cities[i] = Array.ConvertAll(Console.ReadLine().Split(' '), citiesTemp => Convert.ToInt32(citiesTemp));
                }

                long result = roadsAndLibraries(n, c_lib, c_road, cities);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
