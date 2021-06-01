using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation.Easy
{
    class Electronics_Shop
    {
        static int getMoneySpent(int[] keyboards, int[] drives, int b)
        {

            int close = -1;
            for (int i = 0; i < keyboards.Length; i++)
            {

                for (int j = 0; j < drives.Length; j++)
                {
                    int sum = keyboards[i] + drives[j];
                    if (sum == b)
                    {
                        return b;
                    }
                    else {
                        if (b > sum)
                        {
                            if (close < sum)
                            {
                                close = sum;
                            }
                        }
                    }
                }
            }
            return close;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] bnm = Console.ReadLine().Split(' ');

            int b = Convert.ToInt32(bnm[0]);

            int n = Convert.ToInt32(bnm[1]);

            int m = Convert.ToInt32(bnm[2]);

            int[] keyboards = Array.ConvertAll(Console.ReadLine().Split(' '), keyboardsTemp => Convert.ToInt32(keyboardsTemp))
            ;

            int[] drives = Array.ConvertAll(Console.ReadLine().Split(' '), drivesTemp => Convert.ToInt32(drivesTemp))
            ;
            /*
             * The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
             */

            int moneySpent = getMoneySpent(keyboards, drives, b);

            textWriter.WriteLine(moneySpent);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
