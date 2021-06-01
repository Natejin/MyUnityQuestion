using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class AppleandOrange
    {
        static void countApplesAndOranges(int s, int t, int a, int b, int[] apples, int[] oranges)
        {
            int appleStartDist = s - a;
            int appleEndDist = t - a;
            int orangeStartDist = t - b;
            int orangeendDist = s - b;
            int appleCount = 0;
            for (int i = 0; i < apples.Length; i++)
            {
                if (appleStartDist <= apples[i] && appleEndDist >= apples[i])
                {
                    appleCount++;
                }
            }

            int orangeCount = 0;
            for (int i = 0; i < oranges.Length; i++)
            {
                if (orangeStartDist >= oranges[i] && orangeendDist <= oranges[i])
                {
                    orangeCount++;
                }
            }

            Console.WriteLine("{0} {1}", appleCount, orangeCount);

        }
    }
}
