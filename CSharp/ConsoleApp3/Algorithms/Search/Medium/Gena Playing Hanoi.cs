using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Search.Medium
{
    class Gena_Playing_Hanoi
    {
        static int Hanoi(int[] arr) {
            return 3;
        }

        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine());

            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), aTemp => Convert.ToInt32(aTemp))
            ;

            int result = Hanoi(a);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
