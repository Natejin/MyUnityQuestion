using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    //네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다.
    //예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고,
    //컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때
    //컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다.
    //따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

    //컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때,
    //네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

    class 네트워크
    {
        public int solution(int n, int[,] computers)
        {
            int answer = 0;
            bool[] detected = new bool[n];
            Queue<int> searchNode = new Queue<int>();
            ////searchNode.Enqueue(0);
            for (int i = 0; i < n; i++)
            {
                if (!detected[i]) searchNode.Enqueue(i);
                else continue;
                while (searchNode.Count > 0)
                {
                    int crtNode = searchNode.Dequeue();
                    detected[crtNode] = true;
                    for (int j = i+1; j < n; j++)
                    {
                        if (!detected[j] && computers[crtNode, j] == 1)
                        {
                            searchNode.Enqueue(j);
                        }
                    }

                }
                answer++;
            }

            for (int i = 0; i < detected.Length && !detected[i]; i++)
            {
                answer++;
            }
            return answer;
        }

        public int solution1(int n, int[,] computers)///TODO 작동불가 이유불명
        {
            int answer = 0;
            bool[] computersBool = new bool[n];
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (computersBool[j]) continue;
                    if (computers[i, j] == 1)
                    {
                        computersBool[j] = true;
                    }
                }
                if (!computersBool[i])
                {
                    computersBool[i] = true;
                    answer++;
                }
            }
            return answer;
        }
    }
}
