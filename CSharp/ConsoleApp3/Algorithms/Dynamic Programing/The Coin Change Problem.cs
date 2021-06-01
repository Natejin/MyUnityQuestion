using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Dynamic_Programming
{
    class The_Coin_Change_Problem
    {
        public static long getWays(int n, List<long> c)
        {
            long[] memArr = new long[n + 1];
            memArr[0] = 1;
            foreach (var item in c)
                for (long i = item; i < n + 1; i++)
                    memArr[i] += memArr[i - item];
            return memArr[n];
        }

        public static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');

            int n = Convert.ToInt32(firstMultipleInput[0]);

            int m = Convert.ToInt32(firstMultipleInput[1]);

            List<long> c = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(cTemp => Convert.ToInt64(cTemp)).ToList();

            // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

            long ways = getWays(n, c);

            textWriter.WriteLine(ways);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
