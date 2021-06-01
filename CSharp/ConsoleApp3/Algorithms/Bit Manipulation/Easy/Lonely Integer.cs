using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Bit_Manipulation
{
    class Lonely_Integer
    {
        static int lonelyinteger(int[] a) {
            int val = 0;
            foreach (var num in a)
            {
                Console.WriteLine("val {0} ^ num {1} = ans {2}", val, num, val ^ num);
                val = val ^ num; // ^ is XOR operator
            
            }
            return val;
        }

        static int lonelyinteger1(int[] a)
        {
            Dictionary<int, int> keyValuePairs = new Dictionary<int, int>();
            Dictionary<int, int> NotAnswer = new Dictionary<int, int>();
            for (int i = 0; i < a.Length; i++)
            {
                if (keyValuePairs.ContainsKey(a[i]))
                {
                    NotAnswer.Remove(a[i]);
                }
                else
                {
                    keyValuePairs.Add(a[i], 1);
                    NotAnswer.Add(a[i], 1);
                }
            }

            return NotAnswer.Keys.ToArray()[0];
        }
    

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), aTemp => Convert.ToInt32(aTemp))
            ;
            int result = lonelyinteger(a);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
