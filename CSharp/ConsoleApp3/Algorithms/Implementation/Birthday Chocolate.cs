using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Birthday_Chocolate
    {
        // Complete the birthday function below.
        static int birthday(List<int> s, int d, int m)
        {
            int[] DPArr = new int[s.Count + 1];
            for (int i = 0; i < s.Count; i++)
            {
                DPArr[i + 1] += DPArr[i] + s[i];
            }

            int count = 0;

            for (int i = m; i < DPArr.Length; i++)
            {
                int tempSum = DPArr[i] - DPArr[i - m];
                if (tempSum == d) count++;
            }

            return count;
        }
        //5
        //1 2 1 3 2
        //3 2
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine().Trim());

            List<int> s = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(sTemp => Convert.ToInt32(sTemp)).ToList();

            string[] dm = Console.ReadLine().TrimEnd().Split(' ');

            int d = Convert.ToInt32(dm[0]);

            int m = Convert.ToInt32(dm[1]);

            int result = birthday(s, d, m);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
