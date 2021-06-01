using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_25_Running_Time_and_Complexity
    {
        static string[] FindPrime(int[] arr)
        {
            int count = 0;
            string[] ans = new string[arr.Length]; 
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] == 1)
                {
                    ans[i] = "Not prime"; //NOT PRIME
                    continue;
                }
                int sq = (int)Math.Sqrt(arr[i]);
                bool isPrime = true;
                for (int j = 2; j <= sq; j++)
                {
                    count++;
                    if (arr[i] % j == 0)
                    {
                        ans[i] = "Not prime"; //NOT PRIME
                        isPrime = false;
                        break;
                    }
                }
                if (isPrime)
                {
                    ans[i] = "Prime";
                }
            }
            Console.WriteLine("연산 : {0}",count);
            return ans;
        }

        static void Main(String[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            int[] a = new int[T];
            int i = 0;
            while (T-- > 0)
            {
                a[i] = Int32.Parse(Console.ReadLine());
                i++;
            }
            string[] sa = FindPrime(a);
            for (int j = 0; j < sa.Length; j++)
            {
                Console.WriteLine(sa[j]);
            }
        }
    }
}
