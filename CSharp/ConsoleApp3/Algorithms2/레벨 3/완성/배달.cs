using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    class 배달
    {
        //N개의 마을로 이루어진 나라가 있습니다.이 나라의 각 마을에는 1부터 N까지의 번호가 각각 하나씩 부여되어 있습니다.각 마을은 양방향으로 통행할 수 있는 도로로 연결되어 있는데, 서로 다른 마을 간에 이동할 때는 이 도로를 지나야 합니다.도로를 지날 때 걸리는 시간은 도로별로 다릅니다. 현재 1번 마을에 있는 음식점에서 각 마을로 음식 배달을 하려고 합니다. 각 마을로부터 음식 주문을 받으려고 하는데, N개의 마을 중에서 K 시간 이하로 배달이 가능한 마을에서만 주문을 받으려고 합니다. 다음은 N = 5, K = 3인 경우의 예시입니다.

        //위 그림에서 1번 마을에 있는 음식점은 [1, 2, 4, 5] 번 마을까지는 3 이하의 시간에 배달할 수 있습니다.그러나 3번 마을까지는 3시간 이내로 배달할 수 있는 경로가 없으므로 3번 마을에서는 주문을 받지 않습니다.따라서 1번 마을에 있는 음식점이 배달 주문을 받을 수 있는 마을은 4개가 됩니다.
        //마을의 개수 N, 각 마을을 연결하는 도로의 정보 road, 음식 배달이 가능한 시간 K가 매개변수로 주어질 때, 음식 주문을 받을 수 있는 마을의 개수를 return 하도록 solution 함수를 완성해주세요.
        public int solution(int N, int[,] road, int K)
        {
            //배열 생성
            int[] cityCostArr = new int[N + 1];

            //초기화
            for (int i = 0; i <= N; i++)
            {
                cityCostArr[i] = int.MaxValue;
            }
            cityCostArr[1] = 0;

            //큐 초기화
            Queue<int> que = new Queue<int>();
            que.Enqueue(1); // 시작위치 집어넣기
            while (que.Count() > 0)
            {
                int nCurrent = que.Dequeue();
                // 출발지가 i인 곳에 연결된 마을의 Cost를 설정
                for (int i = 0; i < road.GetLength(0); i++)
                {
                    int nStart = road[i, 0];
                    int nEnd = road[i, 1];
                    int nCost = road[i, 2];
                    if (nStart == nCurrent)
                    {
                        if (cityCostArr[nEnd] > nCost + cityCostArr[nStart])
                        {
                            cityCostArr[nEnd] = nCost + cityCostArr[nStart];
                            que.Enqueue(nEnd);
                        }
                    }
                    else if (nEnd == nCurrent)
                    {
                        if (cityCostArr[nStart] > nCost + cityCostArr[nEnd])
                        {
                            cityCostArr[nStart] = nCost + cityCostArr[nEnd];
                            que.Enqueue(nStart);
                        }
                    }
                }
            }
            return cityCostArr.Where(x => x <= K).Count();
        }
    }
}