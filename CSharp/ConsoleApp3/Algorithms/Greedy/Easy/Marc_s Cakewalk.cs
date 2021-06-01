using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy
{
    class Marc_s_Cakewalk
    {
        static long marcsCakewalk(int[] calorie)
        {
            calorie = calorie.OrderByDescending(x => x).ToArray();
            long total = 0;
            long multiple = 1;
            for (int i = 0; i < calorie.Length; i++)
            {
                total += calorie[i] * multiple;
                multiple *= 2;
            }
            return total;
        }
        //4
        //7 4 9 6
        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] calorie = Array.ConvertAll(Console.ReadLine().Split(' '), calorieTemp => Convert.ToInt32(calorieTemp))
            ;
            long result = marcsCakewalk(calorie);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
