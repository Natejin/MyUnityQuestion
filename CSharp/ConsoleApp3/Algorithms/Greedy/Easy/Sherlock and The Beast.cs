using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Easy
{
    class Sherlock_and_The_Beast
    {
        static void decentNumber(int n)
        {

            //say 5x + 3y = n, then
            //y = (n - 5x)/ 3 must be a whole number for some value of x

            int x = 0;


            int y = 0;
            while ((n - 5 * x) % 3 != 0 && y >= 0)
            {
                x += 1;
                y = (n - 5 * x) / 3;
            }

            y = (n - 5 * x) / 3;
            if (y < 0) Console.WriteLine("-1");
            string answer = String.Concat(Enumerable.Repeat("555", y));
            answer += String.Concat(Enumerable.Repeat("33333", x));
            Console.WriteLine(answer);
        }


        // Complete the decentNumber function below.
        static void decentNumber1(int n)
        {
            if (n <= 7)
            {
                if (n == 1 || n == 2 || n == 4 || n == 7)
                {
                    Console.WriteLine(-1);
                }
                else {
                    switch (n)
                    {
                        case 3:
                            Console.WriteLine(555);
                            break;
                        case 5:
                            Console.WriteLine(33333);
                            break;
                        case 6:
                            Console.WriteLine(555555);
                            break;
                        default:
                            break;
                    }
                }
            }
            else {
                int reminder = n % 3;
                int num3 = 0;
                int num5 = 0;
                switch (reminder)
                {
                    case 1:
                        num5 = 2;
                        num3 = (n - 10) / 3;
                        break;
                    case 2:
                        num5 = 1;
                        num3 = (n - 5) / 3;
                        break;
                    default:
                        num3 = n / 3;
                        break;
                }
                string answer = String.Concat(Enumerable.Repeat("555", num3));
                answer += String.Concat(Enumerable.Repeat("33333", num5));
                Console.WriteLine(answer);
            }
        }

        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine().Trim());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine().Trim());

                decentNumber(n);
            }
        }
    }
}
