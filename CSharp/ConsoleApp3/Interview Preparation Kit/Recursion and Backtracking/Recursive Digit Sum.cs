using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Recursion_and_Backtracking
{
    class Recursive_Digit_Sum
    {
        // Complete the superDigit function below.
        static int superDigit(string n, int k)
        {
            char[] charArr = n.ToCharArray();
            long unitSum = 0;
            for (int i = 0; i < charArr.Length; i++)
            {
                unitSum += charArr[i] - 48;
            }
            unitSum = unitSum * k;
            Console.WriteLine(unitSum);
            string stringType = unitSum.ToString();
            if (stringType.Length > 1)
            {
                return superDigit(stringType, 1);
            }
            else
            {
                return (int)unitSum;
            }
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nk = Console.ReadLine().Split(' ');

            string n = nk[0];

            int k = Convert.ToInt32(nk[1]);

            int result = superDigit(n, k);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
