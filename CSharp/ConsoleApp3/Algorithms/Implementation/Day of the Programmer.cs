using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Day_of_the_Programmer
    {
        static string dayOfProgrammer(int year)
        {
            string answer = "";
            if (year > 1918)
            {
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                {
                    answer = "12.09." + year.ToString();
                }
                else
                {
                    answer = "13.09." + year.ToString();
                }
            }
            else if (year < 1918)
            {
                if (year % 4 == 0)
                {
                    answer = "12.09." + year.ToString();
                }
                else
                {
                    answer = "13.09." + year.ToString();
                }
            }
            else {
                answer = "26.09." + year.ToString();
            }


            return answer;
        }

        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int year = Convert.ToInt32(Console.ReadLine().Trim());

            string result = dayOfProgrammer(year);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
