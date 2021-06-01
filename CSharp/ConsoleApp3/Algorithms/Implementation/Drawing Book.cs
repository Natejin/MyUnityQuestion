using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Drawing_Book
    {
        static int pageCount(int n, int p)
        {
            int divide = p / 2;
            int mid = n / 2 - divide;
            if (mid > divide) mid = divide;
            return mid;

        }

        static int pageCount1(int n, int p)
        {
            int pageCount = 0;
            if (n % 2 == 0)
            {
                if (p % 2 == 1)
                {
                    pageCount += 1;
                }
                
            }

            int fromStart = p / 2;
            int fromLast = (n - p) / 2 + pageCount;

            pageCount = fromStart > fromLast ? fromLast : fromStart;
            return pageCount;

        }

        //2
        //5
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int p = Convert.ToInt32(Console.ReadLine());

            int result = pageCount(n, p);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
