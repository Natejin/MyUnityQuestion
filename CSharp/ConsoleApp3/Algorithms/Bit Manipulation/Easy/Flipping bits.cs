using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Miscellaneous
{
    class Flipping_bits
    {
        static long maxInt = (long)Math.Pow(2, 32) - 1;

        static long flippingBits(long n)
        {
            return n ^ maxInt;
        }

        static long flippingBits1(long n)
        {
            return maxInt - n;
        }

        static void Main(string[] args)
        {

            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int q = Convert.ToInt32(Console.ReadLine());

            for (int qItr = 0; qItr < q; qItr++)
            {
                long n = Convert.ToInt64(Console.ReadLine());

                long result = flippingBits(n);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
