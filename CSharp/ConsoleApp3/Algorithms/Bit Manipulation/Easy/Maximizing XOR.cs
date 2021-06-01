using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Bit_Manipulation
{
    class Maximizing_XOR
    {
        static int LeadingZeros(int x)
        {
            const int numIntBits = sizeof(int) * 8; //compile time constant
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

        static int maximizingXor(int l, int r)
        {
            int xored = l ^ r;
            Console.WriteLine();
            int significantBit = 31 - LeadingZeros(xored);
            return (1 << (significantBit + 1)) - 1;

        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int l = Convert.ToInt32(Console.ReadLine());

            int r = Convert.ToInt32(Console.ReadLine());

            int result = maximizingXor(l, r);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
