using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_7_Arrays
    {
        static int[] reverse(int[] arr) {

            int[] ans = new int[arr.Length];
            for (int i = arr.Length - 1, j = 0; i >= 0; i--, j++)
            {
                ans[i] = arr[j];
            }
            return ans;
        }

        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));

            arr = reverse(arr);

            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(arr[i]);
            }
        }
    }
}
