using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3._10_Days_of_Statistics
{
    class Day_1_Quartiles
    {
        public static int Median(int[] arr)
        {
            int length = arr.Length - 0 + 1;
            int median = 0;
            if (length % 2 != 0)
            {
                median = arr[length / 2];
            }
            else
            {
                median = (arr[length / 2 - 1] + arr[length / 2]) / 2;
            }
            return median;
        }

        public static int Median(int[] arr, int start, int end)
        {
            int length = end - start + 1;
            int median = 0;
            if (length % 2 != 0)
            {
                median = arr[start + length / 2];
            }
            else
            {
                median = (arr[start + length / 2 - 1] + arr[start + length / 2]) / 2;
            }
            return median;
        }


        public static int[] QuartilesMethod(int[] arr) {
            int[] ans = new int[3];

            int[] sortedArr = arr.OrderBy(x => x).ToArray();

            ans[0] = Median(sortedArr, 0, arr.Length / 2 - 1);
            ans[1] = Median(sortedArr, 0, arr.Length - 1);
            if (arr.Length % 2 == 0)
            {
                ans[2] = Median(sortedArr, arr.Length / 2, arr.Length - 1);
            }
            else
            {
                ans[2] = Median(sortedArr, arr.Length / 2 + 1, arr.Length - 1);
            }
            return ans;
        }


        static void Maain(String[] args)
        {


            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr1 = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));

            int[] res = QuartilesMethod(arr1);
            for (int i = 0; i < res.Length; i++)
            {
                textWriter.WriteLine(res[i]);
            }


            textWriter.Flush();
            textWriter.Close();
        }
    }

}
