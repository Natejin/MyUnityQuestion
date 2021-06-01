using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_19_Interfaces
    {
        public interface AdvancedArithmetic
        {
            int divisorSum(int n);
        }

        public class Calculator : AdvancedArithmetic
        {
            public int divisorSum(int n)
            {
                int sum = 0;
                int sqrt = (int)Math.Sqrt(n);
                for (int i = 1; i <= sqrt; i++)
                    if (n % i == 0)
                        sum += i + n / i;
                if (sqrt * sqrt == n)
                    sum -= sqrt;
                return sum;
            }
        }

        static void Main(string[] args)
        {
            int n = Int32.Parse(Console.ReadLine());
            AdvancedArithmetic myCalculator = new Calculator();
            int sum = myCalculator.divisorSum(n);
            Console.WriteLine("I implemented: AdvancedArithmetic\n" + sum);
        }
    }
}
