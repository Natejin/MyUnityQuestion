using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    class 입국심사
    {
        public long solution(int n, int[] times)
        {

            int maxTime = -1;
            foreach (var time in times)
            {
                if (maxTime < time)
                    maxTime = time;
            }
            long min = 1;
            long max = (long)maxTime * (long)n;
            long answer = max;

            while (min <= max)
            {
                long mid = (min + max) / 2;
                long sum = 0;
                for (int i = 0; i < times.Length; i++)
                {
                    sum += mid / times[i];
                }

                if (n > sum) min = mid + 1;
                else
                {
                    if (mid <= answer)
                    {
                        answer = mid;
                    }
                    max = mid - 1;
                }
            }

            return answer;
        }
    }
}
