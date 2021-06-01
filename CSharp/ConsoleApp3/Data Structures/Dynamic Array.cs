using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Data_Structures
{
    class Dynamic_Array
    {
        public static List<int> dynamicArray(int n, List<List<int>> queries)
        {

        }

        public static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');

            int n = Convert.ToInt32(firstMultipleInput[0]);

            int q = Convert.ToInt32(firstMultipleInput[1]);

            List<List<int>> queries = new List<List<int>>();

            for (int i = 0; i < q; i++)
            {
                queries.Add(Console.ReadLine().TrimEnd().Split(' ').ToList().Select(queriesTemp => Convert.ToInt32(queriesTemp)).ToList());
            }

            List<int> result = dynamicArray(n, queries);

            textWriter.WriteLine(String.Join("\n", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
