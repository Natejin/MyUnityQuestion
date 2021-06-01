using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Dynamic_Programing.Medium
{
    class Construct_the_Array
    {
        static long countArray(int n, int k, int x)
        {
            long total = 0;
            long[,] dp = new long[n,3];


            dp[1,1] = 1;                 // because array always strts with 1
            int i;
            //-----------------------main loop-------------------------------------
            for (i = 2; i < n; i++)
            {
                // to calculate for value 1
                dp[i,1] = (dp[i - 1,2] * (k - 1)) % 1000000007;

                //to calculate other than 1        
                dp[i,2] = (dp[i - 1,1] + (dp[i - 1,2] * (k - 2))) % 1000000007;
            }
            //------------------------------------------------------    

            if (x == 1)
                total = ((k - 1) * dp[i - 1,2]) % 1000000007;
            else
                total = ((k - 2) * dp[i - 1,2] + dp[i - 1,1]) % 1000000007;

            return (total);
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nkx = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nkx[0]);

            int k = Convert.ToInt32(nkx[1]);

            int x = Convert.ToInt32(nkx[2]);

            long answer = countArray(n, k, x);

            textWriter.WriteLine(answer);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
