using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_3_Intro_to_Conditional_Statements
    {
        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            if (N % 2 == 1 || (N > 5 && 21 > N))
                Console.WriteLine("Weird");
            else 
                Console.WriteLine("Not Weird");
        }
    }
}
