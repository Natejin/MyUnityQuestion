using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Sorting.Easy
{
    class Big_Sorting
    {
        static string[] bigSorting(string[] unsorted)
        {
            Array.Sort(unsorted, (string a, string b) => {
                if (a.Length == b.Length)
                    return string.Compare(a, b, StringComparison.Ordinal);
                return a.Length - b.Length;
            });
            return unsorted;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            string[] unsorted = new string[n];

            for (int i = 0; i < n; i++)
            {
                string unsortedItem = Console.ReadLine();
                unsorted[i] = unsortedItem;
            }

            string[] result = bigSorting(unsorted);

            textWriter.WriteLine(string.Join("\n", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
