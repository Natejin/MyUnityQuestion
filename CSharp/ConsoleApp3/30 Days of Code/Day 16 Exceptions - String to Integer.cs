using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_16_Exceptions___String_to_Integer
    {
        static void Main(String[] args)
        {
            string S = Console.ReadLine();
            try
            {
                Console.WriteLine(Convert.ToInt32(S));
            }
            catch (Exception)
            {

                Console.WriteLine("Bad String");
            }
        }
    }
}
