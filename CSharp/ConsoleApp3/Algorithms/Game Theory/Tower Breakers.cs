using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Game_Theory
{
    class Tower_Breakers
    {
        static int towerBreakers(int n, int m)
        {
            return m != 1 && n % 2 == 1 ? 1 : 2;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                string[] nm = Console.ReadLine().Split(' ');

                int n = Convert.ToInt32(nm[0]);

                int m = Convert.ToInt32(nm[1]);

                int result = towerBreakers(n, m);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
