using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_29_Bitwise_AND
    {
        static int max(int n, int k)
        {
            if ((k - 1 | k) <= n)
            {
                return (k - 1);
            }
            else
            {
                return (k - 2);
            }
        }

        static int max1(int n, int k)
        {
            int ans = 0;
            for (int A = 1; A < n; A++)
            {
                for (int B = A + 1; B <= n; B++)
                {
                    int S = A & B;
                    if (S < k && S > ans)
                    {
                        if (S == k - 1)
                        {
                            return S;
                        }
                        ans = S;
                    }
                }
            }

            return ans;
        }


        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);
            int t = Convert.ToInt32(Console.ReadLine());
            for (int tItr = 0; tItr < t; tItr++)
            {
                string[] nk = Console.ReadLine().Split(' ');
                int n = Convert.ToInt32(nk[0]);
                int k = Convert.ToInt32(nk[1]);
                textWriter.WriteLine(max(n, k));
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}

