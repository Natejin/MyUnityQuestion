using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation.Easy
{
    class Cats_and_a_Mouse
    {
        static string catAndMouse(int x, int y, int z)
        {
            int distanceFromCatA = Math.Abs(x - z);
            int distanceFromCatB = Math.Abs(y - z);
            if (distanceFromCatA > distanceFromCatB) return "Cat A";
            else if ((distanceFromCatA < distanceFromCatB)) return "Cat B";
            else return "Mouse C";
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int q = Convert.ToInt32(Console.ReadLine());

            for (int qItr = 0; qItr < q; qItr++)
            {
                string[] xyz = Console.ReadLine().Split(' ');

                int x = Convert.ToInt32(xyz[0]);

                int y = Convert.ToInt32(xyz[1]);

                int z = Convert.ToInt32(xyz[2]);

                string result = catAndMouse(x, y, z);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
