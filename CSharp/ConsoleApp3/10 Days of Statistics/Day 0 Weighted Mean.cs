using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3._10_Days_of_Statistics
{
    class Day0_Weighted_Mean
    {
        static float Weighted_Mean(int[] arr1, int[] arr2)
        {
            int sumCount = 0;
            int sumWeight = 0;
            for (int i = 0; i < arr1.Length; i++)
            {
                sumWeight += arr1[i] * arr2[i];
                sumCount += arr2[i];
            }
            return sumWeight / sumCount;
        }

        static void Maain(String[] args)
        {


            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr1 = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
            int[] arr2 = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));

            float res = Weighted_Mean(arr1, arr2);
            textWriter.WriteLine(res.ToString("F1"));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
