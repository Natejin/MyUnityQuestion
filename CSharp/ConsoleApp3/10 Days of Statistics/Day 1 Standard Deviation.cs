using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Xml.Schema;

namespace ConsoleApp3._10_Days_of_Statistics
{
    class Day_1_Standard_Deviation
    {


        public static float StandardDeviationMethod(int[] arr)
        {
            int[] ans = new int[3];

            int[] sortedArr = arr.OrderBy(x => x).ToArray();

            float average = 0;
            for (int i = 0; i < sortedArr.Length; i++)
            {
                average += sortedArr[i];
            }
            average = average / sortedArr.Length;
            float total = 0;
            for (int i = 0; i < sortedArr.Length; i++)
            {
                total += (float)Math.Pow((sortedArr[i] - average), 2);
            }
            return(float)Math.Sqrt( total / sortedArr.Length);
        }




        static void Maain(String[] args)
        {


            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr1 = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));

            float res = StandardDeviationMethod(arr1);
            textWriter.WriteLine(res);


            textWriter.Flush();
            textWriter.Close();
        }
    }
}
