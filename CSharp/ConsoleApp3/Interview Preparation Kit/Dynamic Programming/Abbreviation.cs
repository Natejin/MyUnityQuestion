using NateJin;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Dynamic_Programming
{
    class Abbreviation
    {
        static string abbreviation(string a, string b)
        {
            char[] s = a.ToCharArray();
            char[] t = b.ToCharArray();
            int n = s.Length;
            int m = t.Length;
            bool[,] dp = new bool[n + 1,m + 1];
            dp[0,0] = true;
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= m; j++)
                {
                    if (i < n && s[i] >= 'a' && s[i] <= 'z')
                    {
                        dp[i + 1,j] |= dp[i,j];
                    }
                    if (i < n && j < m && s[i] == t[j])
                    {
                        dp[i + 1,j + 1] |= dp[i,j];
                    }
                    if (i < n && j < m && s[i] + 'A' - 'a' == t[j])
                    {
                        dp[i + 1,j + 1] |= dp[i,j];
                    }
                }
            }

            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= m; j++)
                {
                    Console.WriteLine("i: {0}, j: {1}, {2}", i, j, dp[i, j]);
                }
            }

            return dp[n,m] ? "YES" : "NO";
        }



        //1
        //daBcd
        //ABC
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int q = Convert.ToInt32(Console.ReadLine());

            for (int qItr = 0; qItr < q; qItr++)
            {
                string a = Console.ReadLine();

                string b = Console.ReadLine();

                string result = abbreviation(a, b);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
