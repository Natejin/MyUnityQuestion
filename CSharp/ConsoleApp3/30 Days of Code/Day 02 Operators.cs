using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day2_Operators
    {
        static void solve(double meal_cost, int tip_percent, int tax_percent)
        { 
            Console.WriteLine((int)Math.Round((meal_cost * 0.01f * (tip_percent + tax_percent)) + meal_cost));
        }

        static void Maain(string[] args)
        {
            double meal_cost = Convert.ToDouble(Console.ReadLine());

            int tip_percent = Convert.ToInt32(Console.ReadLine());

            int tax_percent = Convert.ToInt32(Console.ReadLine());

            solve(meal_cost, tip_percent, tax_percent);
        }
    }
}
