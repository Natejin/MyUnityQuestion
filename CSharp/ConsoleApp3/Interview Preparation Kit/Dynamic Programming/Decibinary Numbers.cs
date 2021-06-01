using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Dynamic_Programming
{
    class Decibinary_Numbers
    {

        static List<long> memDeciBinaryArr = new List<long>();
        static long decibinaryNumbers(long x)
        {
            return 0;

        }

        //2
        //1104
        //1963

        //11111
        //10406
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int q = Convert.ToInt32(Console.ReadLine());

            for (int qItr = 0; qItr < q; qItr++)
            {
                long x = Convert.ToInt64(Console.ReadLine());

                long result = decibinaryNumbers(x);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
