using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_9_Recursion_3
    {
        static int factorial(int n)
        {
            if ( n == 1) return 1;
            return n * factorial(n - 1);
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int result = factorial(n);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
