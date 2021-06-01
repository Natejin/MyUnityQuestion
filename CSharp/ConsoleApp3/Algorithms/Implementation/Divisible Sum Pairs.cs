using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Divisible_Sum_Pairs
    {

        static int divisibleSumPairs(int n, int k, int[] ar)
        {
            int[] bucket = new int[k];
            int count = 0;
            foreach (int value in ar)
            {
                int modValue = value % k;
                count += bucket[(k - modValue) % k]; // adds # of elements in complement bucket
                bucket[modValue]++;                  // saves in bucket
            }
            return count;

        }

        static int divisibleSumPairs1(int n, int k, int[] ar)
        {
            int count = 0;
            int[] divideArr = new int[ar.Length];
            for (int i = 0; i < ar.Length; i++)
            {
                divideArr[i] = ar[i] % k;
            }

            for (int i = 0; i < ar.Length - 1; i++)
            {
                for (int j = i + 1; j < ar.Length; j++)
                {
                    int temp = divideArr[i] + divideArr[j];
                    if (temp == 0 || temp == k)
                    {
                        count++;
                    }
                }
            }
            return count;

        }

        static int divisibleSumPairs2(int n, int k, int[] ar)
        {
            int count = 0;
            for (int i = 0; i < ar.Length - 1; i++)
            {
                for (int j = i + 1; j < ar.Length; j++)
                {
                    if ((ar[i] + ar[j]) % k == 0)
                    {
                        count++;
                    }
                }
            }
            return count;
        }
        //6 3
        //1 3 2 6 1 2
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nk[0]);

            int k = Convert.ToInt32(nk[1]);

            int[] ar = Array.ConvertAll(Console.ReadLine().Split(' '), arTemp => Convert.ToInt32(arTemp))
            ;
            int result = divisibleSumPairs(n, k, ar);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }

    }

}
