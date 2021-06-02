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

namespace ConsoleApp3.Algorithms.Implementation.Easy.Utopian_Tree
{


    class Result
    {

        /*
         * Complete the 'utopianTree' function below.
         *
         * The function is expected to return an INTEGER.
         * The function accepts INTEGER n as parameter.
         */

        public static int[] answer;


        public static int utopianTree(int n)
        {
            return answer[n];
        }

        public static void SetUpAnswer(int maxIndex) {
            answer = new int[maxIndex];
            bool isDouble = true;
            answer[0] = 1;
            for (int i = 1; i < maxIndex; i++)
            {
                if (isDouble)
                {
                    answer[i] = answer[i - 1] * 2;
            
                }
                else {
                    answer[i] = answer[i - 1] + 1;
                }
                isDouble = !isDouble;
                Console.WriteLine(answer[i]);
            }
        }

    }

    class Solution
    {


        public static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);
            Result.SetUpAnswer(60);
            int t = Convert.ToInt32(Console.ReadLine().Trim());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine().Trim());

                int result = Result.utopianTree(n);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }

}
