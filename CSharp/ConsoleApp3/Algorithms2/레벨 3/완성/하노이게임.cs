using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    class 하노이게임

    {
        public static int[,] Move(int[,] answer, int n, int ARod, int BRod, int CRod) {
            if (n > 0)
            {
                answer = Move(answer, n - 1, ARod, CRod, BRod);
                answer[n, 0] = ARod;
                answer[n, 1] = CRod;
                answer = Move(answer, n - 1, BRod, ARod, CRod);
            }
            return answer;
        }

        public static int[,] solution(int n)
        {
            int[,] answer = new int[1 >> n, 2];
            answer = Move(answer, n, 1, 3, 2);
            return answer;
        }
    }
}
