using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Dynamic_Programming
{
    class Largest_Rectangle
    {



        public static long largestRectangle(int[] height)
        {
            var stack = new Stack<long>();
            var index = 0;
            long largestArea = 0;
            int length = height.Length; // 6
            while (index < length) // true; index = 1; index = 2;
            {
                //     stack empty            going upward
                if (stack.Count == 0 || height[stack.Peek()] < height[index]) // index = 1, false;
                {
                    stack.Push(index++); // 0, index = 1;
                }
                else
                {
                    // going downward and then pop stack, calculate rectangle.

                    long lastHeight = height[stack.Pop()]; // 2
                    long width = stack.Count == 0 ? index : index - stack.Peek() - 1; // 1
                    largestArea = Math.Max(largestArea, lastHeight * width); // 2 * 1
                }
            }

            while (stack.Count > 0)
            {
                long lastHeight = height[stack.Pop()]; // 2
                long width = stack.Count == 0 ? length : length - stack.Peek() - 1; // 1
                largestArea = Math.Max(largestArea, lastHeight * width); // 2 * 1
            }
            return largestArea;
        }


     

        //5
        //1 2 3 4 5
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] h = Array.ConvertAll(Console.ReadLine().Split(' '), hTemp => Convert.ToInt32(hTemp))
                ;
            long result = largestRectangle(h);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
