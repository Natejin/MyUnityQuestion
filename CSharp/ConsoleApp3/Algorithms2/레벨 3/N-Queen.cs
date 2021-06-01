using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    class N_Queen
    {
        static int[] column;
        static int answer;

        public int solution(int n)
        {
            answer = 0;

            for (int i = 0; i < n; ++i)
            {
                column = new int[n];
                column[0] = i;
                backtracking(n, 1);
            }
            return answer;
        }

        private void backtracking(int max, int row)
        {
            if (row == max)
            {
                answer++;
                column[row - 1] = 0;
                return;
            }

            for (int i = 0; i < max; ++i)
            {
                column[row] = i;
                if (isPossible(row))
                    backtracking(max, row + 1);
                else
                    column[row] = 0;
            }
            column[row] = 0;
        }

        private bool isPossible(int row)
        {
            for (int i = 0; i < row; ++i)
            {
                if (column[i] == column[row]) return false;
                if (Math.Abs(row - i) == Math.Abs(column[row] - column[i])) return false;
            }
            return true;
        }
    }
}
