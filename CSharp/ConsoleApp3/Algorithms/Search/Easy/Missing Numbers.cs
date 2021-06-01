using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Search.Easy
{
    class Missing_Numbers
    {
        static int[] missingNumbers(int[] arr, int[] brr)
        {
            Dictionary<int, int> temp = new Dictionary<int, int>();


            for (int i = 0; i < brr.Length; i++)
            {
                if (temp.ContainsKey(brr[i]))
                {
                    temp[brr[i]]++;
                }
                else {
                    temp.Add(brr[i], 1);
                }
            }


            for (int i = 0; i < arr.Length; i++)
            {
                if (temp[brr[i]] > 1)
                {
                    temp[brr[i]]--;
                }
                else
                {
                    temp.Remove(brr[i]);
                }
            }

            List<int> answer = new List<int>();
            foreach (var item in temp)
            {

                for (int i = 0; i <= item.Value; i++)
                {
                    answer.Add(item.Key);
                }
            }
            return answer.OrderBy(x => x).ToArray();
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
            ;
            int m = Convert.ToInt32(Console.ReadLine());

            int[] brr = Array.ConvertAll(Console.ReadLine().Split(' '), brrTemp => Convert.ToInt32(brrTemp))
            ;
            int[] result = missingNumbers(arr, brr);

            textWriter.WriteLine(string.Join(" ", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
