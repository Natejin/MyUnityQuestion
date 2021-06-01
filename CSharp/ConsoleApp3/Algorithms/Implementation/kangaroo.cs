using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Kangaroo
    {
        static string kangaroo(int x1, int v1, int x2, int v2)
        {
            return  ((x2 - x1) *(v2 - v1) < 0 &&(x2 - x1) % (v2 - v1) == 0) ? "NO" : "YES";

        }

        static string kangaroo1(int x1, int v1, int x2, int v2)
        {
            string answer = "NO";

            int distanceA = x1;
            int distanceB = x2;
            if (v2 >= v1) return answer;
            while (distanceA < distanceB)
            {
                distanceA = distanceA + v1;
                distanceB = distanceB + v2;
            }
            if (distanceB == distanceA) answer = "YES";

            return answer;

        }

        //0 2 5 3

        //0 3 4 2
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] x1V1X2V2 = Console.ReadLine().Split(' ');

            int x1 = Convert.ToInt32(x1V1X2V2[0]);

            int v1 = Convert.ToInt32(x1V1X2V2[1]);

            int x2 = Convert.ToInt32(x1V1X2V2[2]);

            int v2 = Convert.ToInt32(x1V1X2V2[3]);

            string result = kangaroo(x1, v1, x2, v2);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
