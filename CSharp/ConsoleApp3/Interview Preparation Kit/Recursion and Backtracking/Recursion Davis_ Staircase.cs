using NateJin;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Recursion_and_Backtracking
{
    
    class Recursion_Davis__Staircase
    {
        static Dictionary<int, int> memoDic = new Dictionary<int, int>();

        static int stepPerms(int n)
        {
            if (n == 0) return 1;
            if (n < 0) return 0;
            return !memoDic.TryGetValue(n, out int val) ? memoDic.AddThenReturn(n, stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3)) : val;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int s = Convert.ToInt32(Console.ReadLine());

            for (int sItr = 0; sItr < s; sItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());

                int res = stepPerms(n);

                textWriter.WriteLine(res);
            }

            textWriter.Flush();
            textWriter.Close();
        }

    }
}
