using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Bit_Manipulation.Memium
{
    class Counter_game
    {
        static long LeadingZeros(long x)
        {
            const long numIntBits = sizeof(int) * 8; //compile time constant
                                                    //do the smearing
            x |= x >> 1;
            x |= x >> 2;
            x |= x >> 4;
            x |= x >> 8;
            x |= x >> 16;
            //count the ones
            x -= x >> 1 & 0x55555555;
            x = (x >> 2 & 0x33333333) + (x & 0x33333333);
            x = (x >> 4) + x & 0x0f0f0f0f;
            x += x >> 8;
            x += x >> 16;
            return numIntBits - (x & 0x0000003f); //subtract # of 1s from 32
        }


        static string counterGame(long n)
        {
            int count = 0;
            //
            while (n % 2 == 0)
            {
                n = n >> 1;
                count++;
            }

            while (n != 1)
            {
                if ((n & 1) == 1)
                    count++;
                n = n >> 1;
            }
            return (count & 1) == 1 ? "Louise" : "Richard";
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                long n = Convert.ToInt64(Console.ReadLine());

                string result = counterGame(n);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
