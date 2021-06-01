using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_26_Nested_Logic
    {
        static int CalculateNestedLogic(int[] returnDay, int[] borrowDay) {
            if (returnDay[2] == borrowDay[2])
            {
                if (returnDay[1] == borrowDay[1])
                {
                    int dif = returnDay[0] - borrowDay[0];
                    return dif > 0 ? dif * 15 : 0;
                }
                else
                {
                    int dif = returnDay[1] - borrowDay[1];
                    return dif > 0 ? dif * 500 : 0;
                }
            }
            else {
                int dif = returnDay[2] - borrowDay[2];
                return dif > 0 ? 10000 : 0;
            }
        }

        static void Main(String[] args)
        {
            int[] returnDay = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
            int[] borrowDay = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
            Console.WriteLine(CalculateNestedLogic(returnDay, borrowDay));
        }
    }
}
