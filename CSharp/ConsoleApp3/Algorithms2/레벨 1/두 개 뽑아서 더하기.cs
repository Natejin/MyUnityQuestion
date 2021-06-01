using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_1
{
    class 두_개_뽑아서_더하기
    {
       // 정수 배열 numbers가 주어집니다.numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.
        public int[] solution(int[] numbers)
        {
            int[] answer = new int[] { };
            Dictionary<int, int> dic = new Dictionary<int, int>();
            int max = numbers.Length - 1;
            for (int i = 0; i < max; i++)
            {
                for (int j = i; j < numbers.Length; j++)
                {
                    int sum = numbers[i] + numbers[j];
                    if (!dic.ContainsKey(sum))
                    {
                        dic.Add(sum, 1);
                    }
                }
            }
            return dic.Keys.OrderBy(x => x).ToArray();
        }
    }
}
