using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Dynamic_Programming
{
    public class Candies
    {
        public static long candies(int n, int[] nums)
        {
            long ans = 0;
            int[] candy = new int[n];

            for (int i = n - 1; i > 0; i--)
            {
                if (nums[i - 1] > nums[i])
                {
                    candy[i - 1] = candy[i] + 1;
                }
            }

            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i] < nums[i + 1] && candy[i] >= candy[i + 1])
                {
                    candy[i + 1] = candy[i] + 1;
                }
                ans += candy[i];
            }

            return n + ans + candy[n - 1];
        }

        //10
        //2
        //4
        //2
        //6
        //1
        //7
        //8
        //9
        //2
        //1
        public static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr = new int[n];

            for (int i = 0; i < n; i++)
            {
                int arrItem = Convert.ToInt32(Console.ReadLine());
                arr[i] = arrItem;
            }

            long result = candies(n, arr);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
