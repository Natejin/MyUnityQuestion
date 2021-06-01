using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Bit_Manipulation.Memium
{
    class Xor_sequence
    {
        static long G(long x)
        {
            long a = x % 8;
            if (a == 0 || a == 1) return x;
            else if (a == 2 || a == 3) return 2;
            else if (a == 4 || a == 5) return x + 2;
            else if (a == 6 || a == 7) return 0;
            return 0;
        }

        static long xorSequence(long l, long r) {
            return G(r) ^ G(l - 1);
        }

        static long xorSequence1(long l, long r)
        {
            long[] a = new long[r + 1];

            a[0] = 0;
            for (long i = 1; i < a.Length; i++)
            {
                a[i] = a[i - 1] ^ i;
                Console.WriteLine(a[i]);
            }

            long answer = a[l];
            for (long i = l + 1; i < a.Length; i++)
            {
                answer = answer ^ a[i];
                Console.WriteLine("ans[{0}] {1}",i,answer);
            }
            return answer;

        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int q = Convert.ToInt32(Console.ReadLine());

            for (int qItr = 0; qItr < q; qItr++)
            {
                string[] lr = Console.ReadLine().Split(' ');

                long l = Convert.ToInt64(lr[0]);

                long r = Convert.ToInt64(lr[1]);

                long result = xorSequence(l, r);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
