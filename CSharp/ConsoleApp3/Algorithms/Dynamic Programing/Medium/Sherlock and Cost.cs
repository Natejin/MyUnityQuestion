using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Dynamic_Programing
{
    class Sherlock_and_Cost
    {
        static int DFC_Cost(int sum, int i, int[] B ) {
            if (i == 0) return sum;
            Console.WriteLine("sum {0}, i {1}, B[i] {2} B[i-1] {3}", sum, i, B[i], B[i - 1]);
            return DFC_Cost(sum + Math.Abs(B[i] - B[i - 1]), --i, B);
        }

        static int cost(int[] B)
        {
            int n = B.Length;

            int hi = 0, low = 0;
            for (int i = 1; i < n; i++)
            {
                int high_to_low_diff = B[i - 1] - 1;

                int low_to_high_diff = B[i] - 1;

                int high_to_high_diff = Math.Abs(B[i] - B[i - 1]);

                int low_next = Math.Max(low, hi + high_to_low_diff);
                int hi_next = Math.Max(hi + high_to_high_diff, low + low_to_high_diff);
                low = low_next;
                hi = hi_next;
            }
            return Math.Max(hi, low);
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());

                int[] B = Array.ConvertAll(Console.ReadLine().Split(' '), BTemp => Convert.ToInt32(BTemp))
                ;
                int result = cost(B);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
