using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_10_Binary_Numbers
    {
        static int FindContinueBinary(int num) {
            int continueBinary = 0;
            int currentlyContinue = 0;
            while (num > 0)
            {
                if ((num & 1) == 1)
                {
                    currentlyContinue++;
                }
                else
                {
                    if (continueBinary < currentlyContinue)
                    {
                        continueBinary = currentlyContinue;
                    }
                    currentlyContinue = 0;
                }
                num >>= 1;
            }

            return continueBinary < currentlyContinue ? currentlyContinue : continueBinary;
        }


        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(FindContinueBinary(n));
        }
    }
}
