using System;
using System.Buffers;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation.Easy
{
    class Picking_Numbers
    {
        public static int pickingNumbers(List<int> a)
        {
           var arr = a.OrderBy(x => x).ToArray();
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < arr.Length; i++)
            {
                if (dic.ContainsKey(arr[i]))
                {
                    dic[arr[i]]++;
                }
                else {
                    dic.Add(arr[i], 1);
                }
            }

            var dicKey = dic.Keys.OrderBy(x => x).ToArray();
            int answer = dic[dicKey[0]];

            for (int i = 1; i < dicKey.Length; i++)
            {
                if (dicKey[i - 1] + 1 == dicKey[i])
                {
                    int tempCount = dic[dicKey[i]] + dic[dicKey[i - 1]];
                    if (answer < tempCount)
                    {
                        answer = tempCount;
                    }
                }
                else {
                    if (answer < dic[dicKey[i]])
                    {
                        answer = dic[dicKey[i]];
                    }
                }

            }
            return answer;
        }

        public static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine().Trim());

            List<int> a = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(aTemp => Convert.ToInt32(aTemp)).ToList();

            int result = pickingNumbers(a);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
