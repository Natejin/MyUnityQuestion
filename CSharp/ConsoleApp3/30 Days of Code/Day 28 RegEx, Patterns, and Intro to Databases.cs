using ConsoleApp3.Algorithms.Game_Theory;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_28_RegEx__Patterns__and_Intro_to_Databases
    {
        static List<string> Output(List<string[]> input) {
            List<string> ans = new List<string>();
            Regex alphabet = new Regex(@"[^a-z]");
            Regex gmail = new Regex(@"@gmail.com");
            Regex mail = new Regex(@"[^a-z@.]");
            for (int i = 0; i < input.Count; i++)
            {

                if (input[i][0].Length <= 20 && input[i][1].Length <= 50 && !alphabet.IsMatch(input[i][0]) && !mail.IsMatch(input[i][1])&& gmail.IsMatch(input[i][1]))
                {
                    ans.Add(input[i][0]);
                }
    
            }
            ans = ans.OrderBy(x => x).ToList();
            return ans;
        }

        static void Main(string[] args)
        {
            int N = Convert.ToInt32(Console.ReadLine());
            List<string[]> input = new List<string[]>();
            for (int NItr = 0; NItr < N; NItr++)
            {
                input.Add(Console.ReadLine().Split(' '));
            }
            var output = Output(input);

            for (int i = 0; i < output.Count; i++)
            {
                Console.WriteLine(output[i]);
            }


        }
    }
}
