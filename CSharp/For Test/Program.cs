using System;
using System.IO;
using System.Linq;

namespace For_Test
{

    class Result
    {
        public static int beautifulDays(int i, int j, int k)
        {
            int answer = 0;
            if (j < k)
            {

                return 0;
            }

            for (int a = i; a <= j; a++)
            {
                //var charArray = i.ToString().ToCharArray();
                //string finalResult = ReverseInput(new string(charArray, 0, charArray.Length)).TrimStart('0');

                int temp = a.ToString().Reverse().Aggregate(0, (b, x) => 10 * b + x - '0');

                Console.WriteLine(i + " - " +  temp + " = " + Math.Abs(i - temp) + " % " + k + " = " + Math.Abs(i - temp) % (float)k);

                if (Math.Abs(i - temp) % k == 0)
                {
                    answer++;
                }
                i++;
            }
            return answer;
        }

        static string ReverseInput(string inputString)
        {
            char[] charArray = inputString.ToCharArray();
            Array.Reverse(charArray);
            //Console.WriteLine(charArray);
            return new string(charArray);
        }
    }




    class Program
    {
     
        

        static void Main(string[] args)
        {
            //TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');

            int i = Convert.ToInt32(firstMultipleInput[0]);

            int j = Convert.ToInt32(firstMultipleInput[1]);

            int k = Convert.ToInt32(firstMultipleInput[2]);

            int result = Result.beautifulDays(i, j, k);

            Console.WriteLine((result));

            //textWriter.Flush();
            //textWriter.Close();
        }
    }
}
