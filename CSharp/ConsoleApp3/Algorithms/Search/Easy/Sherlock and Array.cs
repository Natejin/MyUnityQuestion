using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Search.Easy
{
    class Sherlock_and_Array
    {

        static string balancedSums(List<int> arr) {
            int x = 0;
            int sum = 0;
            foreach (int a in arr)
            {
                sum += a;
            }

            foreach (int y in arr)
            {
                if ( x == sum - y)
                {
                    return "YES";
                }
                x = x + y;
            }
            return "NO";
        }

        static string balancedSums1(List<int> _arr)
        {
            var arr = _arr.ToArray();
            int[] memo = new int[_arr.Count + 1];
            //Console.WriteLine("Start");
            memo[1] = arr[0];
            // Console.WriteLine("memo1 {0}", memo[1]);
            for (int i = 1; i < arr.Length; i++)
            {

                memo[i + 1] = (memo[i] + arr[i]);
                //Console.WriteLine("prememo{0} arr{1}", memo[i + 1], arr[i]);
            }


            int maxLength = _arr.Count;
            for (int i = 1; i <= maxLength; i++)
            {
                //Console.WriteLine("{0} {1}", memo[i - 1], memo[maxLength] - memo[i]);
                if (memo[i - 1] == memo[maxLength] - memo[i])
                {
                    return "YES";
                }
            }
            return "NO";
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int T = Convert.ToInt32(Console.ReadLine().Trim());

            for (int TItr = 0; TItr < T; TItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine().Trim());

                List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

                string result = balancedSums(arr);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
