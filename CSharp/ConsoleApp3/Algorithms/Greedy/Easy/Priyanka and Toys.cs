using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Easy
{
    class Priyanka_and_Toys
    {
        static int toys(int[] w)
        {
            Array.Sort(w);
            int i = 0, count = 0, b;
            while (i != w.Length)
            {
                count++;
                b = w[i] + 4;
                while (i != w.Length && w[i] <= b)
                    i++;
                if (i == w.Length) break;
            }
            return count;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] w = Array.ConvertAll(Console.ReadLine().Split(' '), wTemp => Convert.ToInt32(wTemp))
            ;
            int result = toys(w);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
