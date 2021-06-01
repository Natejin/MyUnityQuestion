using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    class 풍선_터트리기
    {
        public int solution(int[] a)
        {
            int[] left = new int[a.Length];
            int[] right = new int[a.Length];
            left[0] = a[0];
            right[a.Length - 1] = a[a.Length - 1];
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 1, j = a.Length - 2; i < a.Length; i++, j--)
            {
                left[i] = Math.Min(a[i], left[i - 1]);
                right[j] = Math.Min(a[j], right[j + 1]);
                dic.TryAdd(left[i], 1);
                dic.TryAdd(right[i], 1);
            }
            return dic.Count;
        }

        public int solution1(int[] a)
        {
            int answer = a.Length;
            int[] left = new int[a.Length];
            int[] right = new int[a.Length];
            left[0] = a[0];
            right[a.Length - 1] = a[a.Length - 1];
            for (int i = 1, j = a.Length - 2; i < a.Length; i++, j--)
            {
                left[i] = Math.Min(a[i], left[i - 1]);
                right[j] = Math.Min(a[j], right[j + 1]);
            }

            for (int i = 0; i < a.Length; i++)
            {
                if (a[i] > left[i] && a[i] > right[i])
                {
                    answer--;
                }
            }
            return answer;
        }
    }
}
