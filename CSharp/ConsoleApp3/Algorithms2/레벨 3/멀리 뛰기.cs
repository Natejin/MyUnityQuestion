using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    class 멀리_뛰기
    {
        public long solution(int n)
        {
            if (n == 1) return 1;
            if (n == 2) return 2;
            long answer = 3;
            long last = 2;
            long before = 1;
            for (int i = 3; i <= n; i++)
            {
                answer = last % 1234567 +  before % 1234567;
                before = last;
                last = answer;
            }
            return answer % 1234567;
        }
    }
}
