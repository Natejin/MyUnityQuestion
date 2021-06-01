using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Breaking_the_Records
    {
        static int[] breakingRecords(int[] scores)
        {
            int max = scores[0];
            int min = scores[0];

            int maxCount = 0, minCount = 0;

            for (int i = 1; i < scores.Length; i++)
            {
                if (scores[i] > max)
                {
                    max = scores[i];
                    maxCount++;
                }
                else if(scores[i] < min) {
                    min = scores[i];
                    minCount++;
                }
            }
            return new int[2] { maxCount, minCount };
        }


        
        //9
        //10 5 20 20 4 5 2 25 1
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] scores = Array.ConvertAll(Console.ReadLine().Split(' '), scoresTemp => Convert.ToInt32(scoresTemp))
            ;
            int[] result = breakingRecords(scores);

            textWriter.WriteLine(string.Join(" ", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
