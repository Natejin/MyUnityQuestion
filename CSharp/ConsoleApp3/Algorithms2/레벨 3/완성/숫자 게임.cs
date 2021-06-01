﻿using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2
{

    //xx 회사의 2xN명의 사원들은 N명씩 두 팀으로 나눠 숫자 게임을 하려고 합니다.
    //두 개의 팀을 각각 A팀과 B팀이라고 하겠습니다. 숫자 게임의 규칙은 다음과 같습니다.
    //
    //  먼저 모든 사원이 무작위로 자연수를 하나씩 부여받습니다.
    //  각 사원은 딱 한 번씩 경기를 합니다.
    //  각 경기당 A팀에서 한 사원이, B팀에서 한 사원이 나와 서로의 수를 공개합니다.
    //  그때 숫자가 큰 쪽이 승리하게 되고, 승리한 사원이 속한 팀은 승점을 1점 얻게 됩니다.
    //  만약 숫자가 같다면 누구도 승점을 얻지 않습니다.


    //전체 사원들은 우선 무작위로 자연수를 하나씩 부여받았습니다.그다음 A팀은 빠르게 출전순서를 정했고
    //자신들의 출전 순서를 B팀에게 공개해버렸습니다. B팀은 그것을 보고 자신들의
    //최종 승점을 가장 높이는 방법으로 팀원들의 출전 순서를 정했습니다.이때의 B팀이 얻는 승점을 구해주세요.
    //A 팀원들이 부여받은 수가 출전 순서대로 나열되어있는 배열 A와 i번째 원소가
    //B팀의 i번 팀원이 부여받은 수를 의미하는 배열 B가 주어질 때, B 팀원들이 얻을 수 있는 최대 승점을
    //return 하도록 solution 함수를 완성해주세요.
    //
    //제한사항
    //
    //  A와 B의 길이는 같습니다.
    //  A와 B의 길이는 1 이상 100,000 이하입니다.
    //  A와 B의 각 원소는 1 이상 1,000,000,000 이하의 자연수입니다.

    class 숫자_게임
    {
        public int solution(int[] A, int[] B)
        {
            Array.Sort(A);
            Array.Sort(B);

            int AIndex = 0;
            int BIndex = 0;
            int result = 0;

            if (A[0] >= B[B.Length - 1])
            {
                return 0;
            }

            for (int i = 0; i < A.Length; i++)
            {
                if (A[AIndex] > B[BIndex])
                {
                    BIndex++;
                }
                else if (A[AIndex] == B[BIndex])
                {
                    BIndex++;
                }
                else
                {
                    AIndex++;
                    BIndex++;
                    result++;
                }
            }
            return result;
        }

        public int solution1(int[] A, int[] B)
        {
            int answer = 0;
            Array.Sort(A);
            Array.Sort(B);
            int j = B.Length - 1;

            if (A[0] >= B[B.Length - 1])
                return 0;

            for (int i = A.Length - 1; i >= 0; i--)
                if (A[i] >= B[j])
                    continue;
                else
                {
                    answer++;
                    j--;
                }
            return answer;
        }
    }


}
