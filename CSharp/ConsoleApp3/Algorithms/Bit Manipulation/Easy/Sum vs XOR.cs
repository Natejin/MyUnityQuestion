using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Bit_Manipulation.Easy
{
    class Sum_vs_XOR
    {
        static long sumXor(long n)
        {
            long c = 0;
                
            while (n > 0)
            {
                c += n % 2 == 0 ? 0 : 1;
                n /= 2;
            }
            return (long)Math.Pow(2, c);

        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            long n = Convert.ToInt64(Console.ReadLine().Trim());

            long result = sumXor(n);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
