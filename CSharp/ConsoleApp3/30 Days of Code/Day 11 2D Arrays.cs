using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_11_2D_Arrays
    {
        static int FindNum(int[][] arr) {
            int max = Int32.MinValue;
            for (int i = 0; i < arr.Length - 2; i++)
            {
                for (int j = 0; j < arr[i].Length -2; j++)
                {
                    int current = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
                    if (current > max)
                    {
                        max = current;
                    }
                }
            }
            return max;
        }

        static void Main(string[] args)
        {
            int[][] arr = new int[6][];

            for (int i = 0; i < 6; i++)
            {
                arr[i] = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));
            }
            Console.WriteLine(FindNum(arr));
        }
    }
}
