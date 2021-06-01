using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3._10_Days_of_Statistics
{
    class Day_1_Interquartile_Range
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

        public static float Median(float[] arr, int start, int end)
        {
            int length = end - start + 1;
            float median = 0;
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


        public static int[] QuartilesMethod(int[] arr)
        {
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

        public static float[] QuartilesMethod(float[] arr)
        {
            float[] ans = new float[3];

            float[] sortedArr = arr.OrderBy(x => x).ToArray();

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


        public static float Interquartile_Range(int[] elements, int[] frequency)
        {
            int[] ans = new int[3];
            List<float> tempArr = new List<float>();
            for (int i = 0; i < elements.Length; i++)
            {
                for (int j = 0; j < frequency[i]; j++)
                {
                    tempArr.Add(elements[i]);
                }

            }
            float[] sortedArr = tempArr.OrderBy(x => x).ToArray();

            float[] tempAns = QuartilesMethod(sortedArr);

            return tempAns[2] - tempAns[0];
        }

        static void Maain(String[] args)
        {


            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr1 = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
            int[] arr2 = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
            float res = Interquartile_Range(arr1, arr2);
            textWriter.WriteLine(res);


            textWriter.Flush();
            textWriter.Close();
        }
    }
}
