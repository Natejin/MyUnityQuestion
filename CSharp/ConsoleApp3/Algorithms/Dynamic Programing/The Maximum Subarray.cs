using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Dynamic_Programing
{
    class The_Maximum_Subarray
    {
        static int[] maxSubarray(int[] arr)
        {
            int[] answer = new int[2];

            answer[0] = arr[0];
            int currentSum = answer[0];
            answer[1] = arr[0] > 0 ? arr[0] : 0;
            int maxNumber = arr[0];

            for (int i = 1; i < arr.Length; i++)
            {
                if (maxNumber < arr[i])
                {
                    maxNumber = arr[i];
                }

                if (arr[i] > 0)
                {
                    answer[1] += arr[i];
                }
                currentSum = Math.Max(arr[i] + currentSum, arr[i]);
                answer[0] = Math.Max(currentSum, answer[0]);
            }
            if (answer[1] <= 0)
            {
                answer[1] = maxNumber;
            }
            return answer;


        }


        //6
        //1
        //1
        //6
        //-1 -2 -3 -4 -5 -6
        //2
        //1 -2
        //3
        //1 2 3
        //1
        //-10
        //6
        //1 -1 -1 -1 -1 5      
        //
        //
        //1 1
        //-1 -1
        //1 1
        //6 6
        //-10 -10
        //5 6
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());

                int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
                ;
                int[] result = maxSubarray(arr);

                textWriter.WriteLine(string.Join(" ", result));
            }

            textWriter.Flush();
            textWriter.Close();
        }

    }
}
