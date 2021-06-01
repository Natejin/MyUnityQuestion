using ConsoleApp3.Algorithms.Implementation;
using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Recursion_and_Backtracking
{
    class Recursion_Fibonacci_Numbers
    {
        public static int[] fibonacciN = new int[30];

        public static int Fibonacci(int n) {
            if (n == 0)
            {
                return 0;
            }
            else if (n == 1)
            {
                return 1;
            }
            else if (fibonacciN[n] != 0)
            {
                return fibonacciN[n];
            }
            else
            {
                return fibonacciN[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
            }
        }


        public static int Fibonacci1(int n)
        {
            if (n == 0) return 0;
            if (n == 1) return 1;
            return Fibonacci(n - 1) + Fibonacci(n-2);
        }

        static void Main(String[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine(Fibonacci(n));
        }
    }
}
