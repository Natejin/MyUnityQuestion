using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    //문제 설명


    //회사원 Demi는 가끔은 야근을 하는데요, 야근을 하면 야근 피로도가 쌓입니다.야근 피로도는 야근을 시작한 시점에서 남은 일의 작업량을 제곱하여 더한입  다.Demi는 N시간 동안 야근 피로도를 최소화하도록 일할 겁니다.Demi가 1시간 동안 작업량 1만큼을 처리할 수 있다고 할 때, 퇴근까지 은 N시간과 각 일에 대한 작업량 works에 대해 야근 피로도를 최소화한 값을 리턴하는 함수 solution을 완성해주세요.


    //제한 사항

    //-works는 길이 1 이상, 20,000 이하인 배열입니다.
    //-works의 원소는 50000 이하인 자연수입니다.
    //-n은 1,000,000 이하인 자연수입니다.

    class 야근_지수
    {


        public long solution1(int n, int[] works)
        {
            SortedList<int, int> set = new SortedList<int, int>();
            for (int i = 0; i < works.Length; i++)
            {
                if (set.ContainsKey(works[i]))
                {
                    set[works[i]]++;
                }
                else
                {
                    set.Add(works[i], 1);
                }
            }

            while (n-- > 0)
            {
                var arr = set.Keys.ToArray();
                int size = arr.Length - 1;
                if (set[arr[size]] > 1)
                {
                    set[arr[size]]--;
                }
                else
                {
                    set.Remove(arr[size]);
                }
                arr[size]--;
                if (arr[size] < 0)
                {
                    return 0;
                }
                if (set.ContainsKey(arr[size]))
                {
                    set[arr[size]]++;
                }
                else
                {
                    set.Add(arr[size], 1);
                }
            }
            double answer = 0;
            foreach (var item in set)
            {
                answer += Math.Pow(item.Key, 2) * item.Value;
            }

            return (long)answer;
        }

        public long solution2(int n, int[] works) //느림
        {
            int size = works.Length - 1;
            while (n-- > 0)
            {
                int maxValue = works.Max();
                int maxIndex = works.ToList().IndexOf(maxValue);
                works[maxIndex]--;
                if (works[maxIndex] < 0)
                    return 0;
            }
            double answer = 0;
            foreach (var item in works)
                answer += Math.Pow(item, 2);
            return (long)answer;
        }

        public long solution3(int n, int[] works)
        {
            int size = works.Length - 1;
            Array.Sort(works);
            int currentSelectedIndex = size;
            int sameNum = 1;
            while (n > 0)
            {
                int maxValue = works[currentSelectedIndex];

                for (int i = currentSelectedIndex; i > 0; i--)
                {
                    if (maxValue > works[i - 1])
                    {
                        currentSelectedIndex = i;
                        break;
                    }
                    sameNum++;
                }
                int secondValue = works[currentSelectedIndex - 1];
                int dif = maxValue - secondValue;
                int totalReduce = dif * sameNum;
                if (totalReduce == 0)
                {
                    break;
                }
                if (totalReduce > n)
                {
                    break;
                }
                else
                {
                    for (int i = 0; i < sameNum; i++)
                    {
                        works[currentSelectedIndex + i] = secondValue;
                    }
                    n -= totalReduce;
                }
            }

            while (n-- > 0)
            {
                int maxValue = works.Max();
                int maxIndex = works.ToList().IndexOf(maxValue);
                works[maxIndex]--;
                if (works[maxIndex] < 0)
                    return 0;
            }
            long answer = 0;
            foreach (var item in works)
                answer += (long)Math.Pow(item, 2);
            return answer;
        }



        public long solution(int n, int[] works)
        {

            Array.Sort(works);
            Array.Reverse(works);

            int curIdx = 1;
            int max = works[0];

            while (n > 0 && curIdx < works.Length)
            {
                if (max > works[curIdx])
                {
                    int term = max - works[curIdx];
                    int totalMinus = term * curIdx;

                    if (totalMinus > n)
                    {
                        int average = n / curIdx;
                        int mod = n % curIdx;

                        for (int i = 0; i < curIdx; ++i)
                            works[i] -= average + (i < mod ? 1 : 0);

                        n = 0;
                    }
                    else
                    {
                        for (int i = 0; i < curIdx; ++i)
                            works[i] -= term;

                        n -= totalMinus;
                        max = works[curIdx];
                    }
                }

                ++curIdx;
            }

            if (n > 0)
            {
                int average = n / works.Length;
                int mod = n % works.Length;

                for (int i = 0; i < works.Length; ++i)
                    works[i] -= Math.Min(works[i], average + (i < mod ? 1 : 0));
            }

            long answer = 0;

            for (int i = 0; i < works.Length; ++i)
                answer += works[i] * works[i];

            return answer;


        }
    }
}

