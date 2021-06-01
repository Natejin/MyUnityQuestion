using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day1_Data_Types
    {
        static string[] DataTypes( int n, float f, string s) {
            n = n + (int)f;
            f = f + f;
            s = "HackerRank " + s;
            string[] result = new string[3];
            result[0] = n.ToString();
            result[1] = f.ToString("F1");
            result[2] = s;
            return result;
        }

        // Declare second integer, double, and String variables.

        // Read and save an integer, double, and String to your variables.

        // Print the sum of both integer variables on a new line.

        // Print the sum of the double variables on a new line.

        // Concatenate and print the String variables on a new line
        // The 's' variable above should be printed first.

        static void Maain(String[] args)
        {


            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());
            float f = Convert.ToSingle(Console.ReadLine());
            string s = Console.ReadLine();

            string[] result = DataTypes( n, f, s);
            textWriter.WriteLine(result[0]);
            textWriter.WriteLine(result[1]);
            textWriter.WriteLine(result[2]);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
