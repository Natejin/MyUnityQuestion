using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Miscellaneous
{
  
    class Time_Complexity_Primality
    {
        static List<int> primeDic = new List<int>() { 2 };
        static int currentSave = 2;
        static string primality(int n)
        {
            if (n < 2) return "Not prime";
            else if (n <= 3) return "Prime";
            else if (n % 2 == 0 || n % 3 == 0) return "Not prime";
            else {
                int limit = (int)Math.Sqrt(n) + 1;
                for (int i = 3; i < limit; i += 2)
                    if (n % i == 0) return "Not prime";

            }
            return "Prime";
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int p = Convert.ToInt32(Console.ReadLine());

            for (int pItr = 0; pItr < p; pItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());

                string result = primality(n);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
