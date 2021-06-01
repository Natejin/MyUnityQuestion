using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Data_Structures
{
    class Arrays___DS
    {
        static int[] reverseArray(int[] a)
        {
            Array.Reverse(a);
            return a;

        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int arrCount = Convert.ToInt32(Console.ReadLine());

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
            ;
            int[] res = reverseArray(arr);

            textWriter.WriteLine(string.Join(" ", res));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
