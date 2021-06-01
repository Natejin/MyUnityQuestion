using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Stacks_and_Queues
{
    class Balanced_Brackets
    {
        static string isBalanced(string s)
        {
            char[] charArr = s.ToCharArray();
            int size = charArr.Length;
            Stack<char> charStack = new Stack<char>();


            for (int i = 0; i < size; i++)
            {

                switch (charArr[i])
                {
                    case '{':
                        charStack.Push('}');
                        break;
                    case '[':
                        charStack.Push(']');
                        break;
                    case '(':
                        charStack.Push(')');
                        break;
                    default:
                        if (charStack.Count == 0 ||  charStack.Pop() != charArr[i])
                            return "NO";
                        break;
                }
            }

            if (charStack.Count > 0) return "NO";
            return "YES";
        }


        //5
        //{[()]}
        //{[(])}
        //{{[[(())]]}}
        //{(([])[])[]}
        //{}{}{}(){{}[]}
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                string s = Console.ReadLine();

                string result = isBalanced(s);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
