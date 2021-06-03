using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;
namespace ConsoleApp3.Algorithms.Implementation.Easy.Beautiful_Days_at_the_Movies
{


    class Result
    {

        /*
         * Complete the 'beautifulDays' function below.
         *
         * The function is expected to return an INTEGER.
         * The function accepts following parameters:
         *  1. INTEGER i
         *  2. INTEGER j
         *  3. INTEGER k
         */
        public static int beautifulDays(int i, int j, int k)
        {
            int answer = 0;
            for (int a = i; a <= j; a++)
            {
                var charArray = i.ToString().ToCharArray();
                string finalResult = ReverseInput(new string(charArray, 0, charArray.Length)).TrimStart('0');
                if (Math.Abs(i - int.Parse(finalResult)) % k == 0)
                {
                    answer++;
                }
                i++;
            }
            return answer;
        }

        static string ReverseInput(string inputString)
        {
            char[] charArray = inputString.ToCharArray();
            Array.Reverse(charArray);
            //Console.WriteLine(charArray);
            return new string(charArray);
        }
    }



    class Solution
    {
        public static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');

            int i = Convert.ToInt32(firstMultipleInput[0]);

            int j = Convert.ToInt32(firstMultipleInput[1]);

            int k = Convert.ToInt32(firstMultipleInput[2]);

            int result = Result.beautifulDays(i, j, k);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
