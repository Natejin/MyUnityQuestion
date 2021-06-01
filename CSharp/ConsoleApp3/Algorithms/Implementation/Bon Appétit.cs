using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Bon_Appétit
    {

        static void bonAppetit(List<int> bill, int k, int b)
        {
            int sum = 0;
            for (int i = 0; i < bill.Count; i++)
            {
                sum += bill[i];
            }

            sum -= bill[k];
            string result = sum / 2 - b == 0 ? "Bon Appetit" : (sum / 2 - b).ToString();
            Console.WriteLine(result);

        }


        //4 1
        //3 10 2 9
        //7
        static void Maain(string[] args)
        {
            string[] nk = Console.ReadLine().TrimEnd().Split(' ');

            int n = Convert.ToInt32(nk[0]);

            int k = Convert.ToInt32(nk[1]);

            List<int> bill = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(billTemp => Convert.ToInt32(billTemp)).ToList();

            int b = Convert.ToInt32(Console.ReadLine().Trim());

            bonAppetit(bill, k, b);
        }
    }
}
