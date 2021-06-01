using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Midium
{
    class Goodland_Electricity
    {
        static int pylons(int k, int[] arr)
        {

            int result = 0;

            int i = 0;

            while (i < arr.Length)
            {
                bool found = false;
                for (int j = i + k - 1;  j >= 0 && j >=  i - k + 1; j--)
                    if (j < arr.Length)
                        if (arr[j] == 1)
                        {
                            found = true;
                            i = j + k;
                            result++;
                            break;
                        }
                if (!found) return -1;
            }
            return result;

        }



        //static int pylons(int k, int[] arr)
        //{
        //    int result = 0;

        //    // start from the beginning and find the furthest city to build the plant
        //    int i = 0;

        //    //10 3
        //    //0 1 0 0 0 1 1 1 1 1
        //    while (i < arr.Length)
        //    {
        //        // cout << i << endl;
        //        // do backward search from the furthest possible to current
        //        bool found = false;
        //        for (int j = i + k - 1; (j >= i - k + 1) && (j >= 0); j--)
        //        {
        //            Console.WriteLine("i: {0} j: {1} arr[j]: {2}", i, j, arr[j]);
        //            // cout << " " << j << endl;
        //            if (j < arr.Length)
        //            {
        //                if (arr[j] == 1)
        //                {
        //                    // cout << " = " << j << endl;
        //                    // put plant here and 
        //                    result++;
        //                    // calculate the new beginning
        //                    i = j + k;
        //                    found = true;
        //                    break;
        //                }
        //            }
        //        }

        //        if (!found) return -1;
        //    }

        //    return result;

        //}

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nk[0]);

            int k = Convert.ToInt32(nk[1]);

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
            ;
            int result = pylons(k, arr);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
