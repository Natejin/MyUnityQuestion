using NateJin;
using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_2
{
    class 주식_가격
    {
        public int[] solution(int[] prices)
        {
            Stack<int> beginIdxs = new Stack<int>();
            int i = 0;
            int[] terms = new int[prices.Length];

            beginIdxs.Push(i);
            for (i = 1; i < prices.Length; i++)
            {
                while (!(beginIdxs.Count ==0) && prices[i] < prices[beginIdxs.Peek()])
                {
                    int beginIdx = beginIdxs.Pop();
                    terms[beginIdx] = i - beginIdx;
                }
                beginIdxs.Push(i);
            }
            while (!(beginIdxs.Count == 0))
            {
                int beginIdx = beginIdxs.Pop();
                terms[beginIdx] = i - beginIdx - 1;
            }

            return terms;
        }


        public int[] solution1(int[] prices)
        {
            int[] answer = new int[prices.Length];
            for (int i = 0; i < prices.Length; i++)
            {
                for (int j = i + 1; j < prices.Length; j++)
                {
                    answer[i]++;
                    if (prices[i] > prices[j])
                    {
                        break;
                    }
                }
            }
            return answer;
        }
    }
}
