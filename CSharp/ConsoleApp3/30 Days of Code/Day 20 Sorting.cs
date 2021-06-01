using NateJin;
using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_20_Sorting
    {
        static void Main(String[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            string[] a_temp = Console.ReadLine().Split(' ');
            int[] a = Array.ConvertAll(a_temp, Int32.Parse);
            // Write Your Code Here
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                // Track number of elements swapped during a single array traversal
                int numberOfSwaps = 0;

                for (int j = 0; j < n - 1; j++)
                {
                    // Swap adjacent elements if they are in decreasing order
                    if (a[j] > a[j + 1])
                    {
                        int temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                        numberOfSwaps++;
                    }
                }
                count += numberOfSwaps;
                // If no elements were swapped during a traversal, array is sorted
                if (numberOfSwaps == 0)
                {
                    break;
                }
            }
            Console.WriteLine("Array is sorted in {0} swaps.\nFirst Element: {1}\nLast Element: {2}", count, a[0], a[n -1]);
            


        }
    
    }
}
