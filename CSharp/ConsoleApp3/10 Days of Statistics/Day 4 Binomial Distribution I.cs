using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3._10_Days_of_Statistics
{
    class Day_4_Binomial_Distribution_I
    {
        static void maain(String[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            float[] arr1 = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToSingle(arrTemp));


            double pM = arr1[0] / (arr1[0] + arr1[1]);
            double pF = arr1[1] / (arr1[0] + arr1[1]);
            double p3M = 0;
            for (int i = 0; i < (1 << 6); i++)
            {
                int boys = 0;
                double p = 1;
                for (int j = 0; j < 6; j++)
                {
                    bool isBoy = (i & (1 << j)) != 0;
                    p *= isBoy ? pM : pF;
                    if (isBoy) boys++;
                }
                if (boys >= 3)
                {
                    p3M += p;
                }
            }
            textWriter.WriteLine(p3M.ToString("F3"));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
