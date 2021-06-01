using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Bit_Manipulation.Memium
{
    class The_Great_XOR
    {
        static long theGreatXor(long x)
        {
            // Complete this function
            long result = 0;
            int bitPos = 0;
            while (x > 0)
            {
                Console.WriteLine("Count {0}", x);
                if ((x & 1) == 0)
                {
                    result += (1L << bitPos);
                }
                bitPos++;
                x >>= 1;
              
            }
            return result;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int q = Convert.ToInt32(Console.ReadLine());

            for (int qItr = 0; qItr < q; qItr++)
            {
                long x = Convert.ToInt64(Console.ReadLine());

                long result = theGreatXor(x);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }


    }




}
