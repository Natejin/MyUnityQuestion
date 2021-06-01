using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3._10_Days_of_Statistics
{
    static class Day0_Mean_Median_and_Mode
    {
        static float[] Mean_Median_and_Mode(int[] arr)
        {
            float[] resultArr = new float[3];
            int sum = 0;
            Dictionary<int, int> dic = new Dictionary<int, int>();
            Array.Sort(arr);
            for (int i = 0; i < arr.Length; i++)
            {
                sum += arr[i];
                if (dic.ContainsKey(arr[i]))
                {
                    dic[arr[i]]++;
                }
                else
                {
                    dic.Add(arr[i], 1);
                }

            }
            int maxKey = 10000000;
            int currentCount = 0;
            foreach (var item in dic)
            {
                Console.WriteLine(item.Value);
                if (item.Value > currentCount)
                {
                    maxKey = item.Key;
                    currentCount = item.Value;
                }
                else if(item.Value == currentCount) {
                    if (maxKey > item.Key)
                    {
                        maxKey = item.Key;
                    }
                }
            }

            resultArr[0] = sum / (float)arr.Length;
            resultArr[1] = arr.Length % 2 == 0 ? ((float)arr[arr.Length / 2] + (float)arr[arr.Length / 2 - 1]) / 2f : (float)arr[arr.Length / 2];
            resultArr[2] = maxKey;
            return resultArr;
        }


        static void maain()
        {


            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
            ;
            float[] res = Mean_Median_and_Mode(arr);
            for (int i = 0; i < res.Length; i++)
            {
                textWriter.WriteLine(res[i]);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
