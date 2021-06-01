using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Easy
{
    class Maximum_Perimeter_Triangle
    {
        static int[] maximumPerimeterTriangle(int[] sticks)
        {
            Array.Sort(sticks);
            for (int i = sticks.Length - 3; i > 0; i--)
            {
                if (sticks[i] + sticks[i + 1] > sticks[i + 2])
                {
                    return new int[3] { sticks[i], sticks[i + 1], sticks[i + 2] };
                }
            }
            return new int[1] { -1 };
        }

        static int[] maximumPerimeterTriangle1(int[] sticks)
        {
            Array.Sort(sticks);
            int max = -1;
            int index = 0;
            for (int i = 0; i < sticks.Length -2; i++)
            {
                if (sticks[i] + sticks[i + 1] >  sticks[i +  2] && sticks[i+2] >= max)
                {
                    max = sticks[i + 2];
                    index = i;
                }
            }
            if (max == -1)
            {
                return new int[1] { -1};
            }
            else {
                return new int[3] {sticks[index], sticks[index+1], sticks[index + 2] }; 
            }
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] sticks = Array.ConvertAll(Console.ReadLine().Split(' '), sticksTemp => Convert.ToInt32(sticksTemp))
            ;
            int[] result = maximumPerimeterTriangle(sticks);

            textWriter.WriteLine(string.Join(" ", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
