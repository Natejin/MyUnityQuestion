using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy
{
    class Grid_Challenge
    {
        static string gridChallenge(string[] grid) {
            int n = grid.Length;
            bool is_not = false;
            for (int i = n - 1; i >= 0; i--)
            {
                string r = grid[i];
                String.Concat(r.OrderBy(c => c));

                if (i == n - 1) continue;
                string p = grid[i + 1];

                for (int j = 0; j < p.Length; j++)
                {

                    if ((int)r[j] > (int)p[j])
                    { 
                        is_not = true; break;
                    }
                }
                if (is_not) break;
            }
            return (is_not ? "NO" : "YES");
        }

        static string gridChallenge1(string[] grid)
        {
            int[][] tempGrid = new int[grid.Length][];
            int rowSize = grid[0].ToCharArray().Length;
            for (int i = 0; i < grid.Length; i++)
            {
                var tempCharArr = grid[i].ToCharArray();
                tempGrid[i] = new int[rowSize];
                for (int j = 0; j < rowSize; j++)
                {
                    Console.WriteLine("i {0} j {1} char {2}", i, j, tempCharArr[j]);
                    tempGrid[i][j] = tempCharArr[j];
                }
                tempGrid[i] = tempGrid[i].OrderBy(x => x).ToArray();

                for (int k = 0; k < tempGrid.Length; k++)
                {
                    Console.WriteLine(tempGrid[i][k]);
                    
                }
            }

            for (int j = 0; j < rowSize; j++)
            {
                int tempval = 0;
                for (int i = 0; i < grid.Length; i++)
                {
                    if (grid[i][j] >= tempval)
                    {
                        tempval = grid[i][j];
                    }
                    else {
                        return "NO";
                    }
                }
            }

            return "YES";
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());

                string[] grid = new string[n];

                for (int i = 0; i < n; i++)
                {
                    string gridItem = Console.ReadLine();
                    grid[i] = gridItem;
                }

                string result = gridChallenge(grid);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
