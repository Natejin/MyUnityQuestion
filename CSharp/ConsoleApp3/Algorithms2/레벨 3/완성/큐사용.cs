using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    class 큐사용
    {
        public int[] solution(string[] operations)
        {
            int[] answer = new int[2];
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int max = int.MinValue;
            int min = int.MaxValue;
            for (int i = 0; i < operations.Length; i++)
            {
                var a = operations[i].Split();
                Console.WriteLine("i:{0} a[0]:{1}", i, a[0]);
                if (a[0] == "I")
                {
                    int converted = Convert.ToInt32(a[1]);
                    if (dic.ContainsKey(converted))
                    {
                        dic[converted]++;
                    }
                    else
                    {
                        dic.Add(converted, 1);
                    }
                    if (converted > max)
                    {
                        max = converted;
                    }

                    if (converted < min)
                    {
                        min = converted;
                    }
                }
                else if (a[1] == "1" && dic.Count > 0)
                {
                    dic.Remove(max);
                    if (dic.Keys.Count > 0)
                    {
                        var arr = dic.Keys.OrderBy(x => x).ToArray();
                        max = arr[arr.Length - 1];
                    }
                    else
                    {
                        max = int.MinValue;
                    }


                }
                else if (dic.Count > 0)
                {
                    dic.Remove(min);
                    if (dic.Keys.Count > 0)
                    {
                        min = dic.Keys.OrderBy(x => x).ToArray()[0];
                    }
                    else
                    {
                        min = int.MaxValue;
                    }
                }

            }
            if (dic.Count == 0)
            {
                answer[0] = 0;
                answer[1] = 0;
            }
            else
            {
                answer[0] = max;
                answer[1] = min;
            }
            return answer;
        }
    }
}
