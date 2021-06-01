using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;

namespace ConsoleApp3.Interview_Preparation_Kit.Dynamic_Programming
{
    class Max_Array_Sum
    {

        public static int maxSubsetSum(int[] arr)
        {
            if (arr.Length == 0) return 0;
            arr[0] = Math.Max(0, arr[0]);
            if (arr.Length == 1) return arr[0];
            arr[1] = Math.Max(arr[0], arr[1]);
            for (int i = 2; i < arr.Length; i++)
                arr[i] = Math.Max(arr[i - 1], arr[i] + arr[i - 2]);
            return arr[arr.Length - 1];
        }


        static int max_subArray(int[] arr, int index, Dictionary<int, int> d) {
            if (d.ContainsKey(index)) return d[index];

            if (index == arr.Length - 1) {
                d.Add(index, arr[index]);
            } else if (index == arr.Length - 2) {
                d.Add(index, Math.Max(arr[index], arr[index + 1]));
            }
            else {
                d.Add(index, Math.Max(arr[index], Math.Max(arr[index] + max_subArray(arr, index + 2, d), max_subArray(arr, index + 1, d))));
            }
            return d[index];
        }

        static int maxSubsetSum1(int[] arr)
        {
            if (arr == null || arr.Length == 0) return 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            return max_subArray(arr, 0, dic);
        }
        //5
        //3 5 -7 8 10
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
            int res = maxSubsetSum(arr);

            textWriter.WriteLine(res);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
