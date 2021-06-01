using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;
using System.Text;
using System.Threading;
using NateJin.Vector2;

namespace ConsoleApp3.Interview_Preparation_Kit.Graphs
{
    class DFS_Connected_Cell_in_a_Grid
    {
        // Complete the maxRegion function below.
        static int maxRegion(int[][] grid)
        {
            bool[,] seen = new bool[grid.Length, grid[0].Length];

            int answer = 0;
            for (int i = 0; i < grid.Length; i++)
            {

                for (int j = 0; j < grid[0].Length; j++)
                {
                    if (seen[i,j] == false && grid[i][j] == 1)
                    {

                        Queue<MyVec2Int> searchPos = new Queue<MyVec2Int>();
                        searchPos.Enqueue(new MyVec2Int(i, j));
                        seen[i, j] = true;
                        int count = 0;
                        while (searchPos.Count > 0)
                        {
                            MyVec2Int currentPos = searchPos.Dequeue();
                            count++;
                            int x = currentPos.x;
                            int y = currentPos.y;
                            for (int m = -1; m <= 1; m++)
                            {
                                for (int n = -1; n <= 1; n++)
                                {
                                    if (m == 0 && n == 0 || x + m < 0 || y + n < 0 || x + m >= grid.Length || y + n >= grid[0].Length) continue;
                                    if (seen[x + m, y + n] == false && grid[x + m][y + n] == 1)
                                    {
                                        seen[x + m, y + n] = true;
                                        searchPos.Enqueue(new MyVec2Int(x + m, y + n));
                                    }

                                }
                            }
                        }
                        if (answer < count)
                        {
                            answer = count;
                        }
                    }
                }
            }

            return answer;

        }

        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int m = Convert.ToInt32(Console.ReadLine());

            int[][] grid = new int[n][];

            for (int i = 0; i < n; i++)
            {
                grid[i] = Array.ConvertAll(Console.ReadLine().Split(' '), gridTemp => Convert.ToInt32(gridTemp));
            }

            int res = maxRegion(grid);

            textWriter.WriteLine(res);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
