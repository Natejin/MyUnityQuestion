using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation.Easy
{
    class The_Hurdle_Race
    {
        // Complete the hurdleRace function below.
        static int hurdleRace(int k, int[] height)
        {
            Array.Sort(height);
            int needDrink = k - height[height.Length];
            if (needDrink < 0)
            {
                needDrink = 0;
            }
            return needDrink;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nk[0]);

            int k = Convert.ToInt32(nk[1]);

            int[] height = Array.ConvertAll(Console.ReadLine().Split(' '), heightTemp => Convert.ToInt32(heightTemp))
            ;
            int result = hurdleRace(k, height);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
