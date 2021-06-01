using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Search.Easy_
{
    class Ice_Cream_Parlor
    {
        private static object oProp;

        static int[] icecreamParlor(int m, int[] arr)
        {
            var tempArr = arr.ToList();
            Array.Sort(arr);
            int largestIndex = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] >= m)
                {
                    largestIndex = i - 1;
                    break;
                }
                if (i == arr.Length-1)
                {
                    largestIndex = arr.Length - 1;
                }
            }

            int smallestIndex = 0;
            while (largestIndex != smallestIndex)
            {
                if (arr[largestIndex] + arr[smallestIndex] > m)
                {
                    largestIndex--;
                }
                else if (arr[largestIndex] + arr[smallestIndex] < m)
                {
                    smallestIndex++;
                }
                else {
                    Console.WriteLine("small {0} large {1}", smallestIndex, largestIndex);
                    var smallAns = tempArr.FindIndex(a => a == smallestIndex) + 1;
                    var largeAns = tempArr.FindIndex(a => a == largestIndex) + 1;

                    if (largeAns < smallAns)
                    {
                        var temp = smallAns;
                        smallAns = largeAns;
                        largeAns = temp;
                    }
                    if (smallAns == largeAns)
                    {
                        largeAns++;
                    }
                    return new int[2] { smallAns, largeAns };
                }
            }
            return new int[0];
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int m = Convert.ToInt32(Console.ReadLine());

                int n = Convert.ToInt32(Console.ReadLine());

                int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
                ;
                int[] result = icecreamParlor(m, arr);

                textWriter.WriteLine(string.Join(" ", result));
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
