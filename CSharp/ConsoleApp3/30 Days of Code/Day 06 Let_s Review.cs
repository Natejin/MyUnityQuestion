using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_6_Let_s_Review
    {
        static string Review(string readString)
        {

            for (int i = 0; i < readString.Length; i+=2)
            {
                Console.Write(readString[i]);
            }
            Console.Write(" ");
            for (int i = 1; i < readString.Length; i += 2)
            {
                Console.Write(readString[i]);
            }
            return "";
        }

        static string Review1(string readString) {
            string front = "";
            string back = "";
            char[] charArr = readString.ToCharArray();
            for (int i = 0; i < charArr.Length; i++)
            {
                if (i % 2 == 1)
                {
                    back += charArr[i];
                }
                else {
                    front += charArr[i];
                }
            }
            return front + " " + back;
        }
        static void Main(String[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                Console.WriteLine(Review( Console.ReadLine()));
            }
        }
    }
}
