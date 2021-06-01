using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    //n개의 노드가 있는 그래프가 있습니다.각 노드는 1부터 n까지 번호가 적혀있습니다. 1번 노드에서 가장 멀리 떨어진 노드의 갯수를 구하려고 합니다.가장 멀리 떨어진 노드란 최단경로로 이동했을 때 간선의 개수가 가장 많은 노드들을 의미합니다.
    //
    //노드의 개수 n, 간선에 대한 정보가 담긴 2차원 배열 vertex가 매개변수로 주어질 때, 1번 노드로부터 가장 멀리 떨어진 노드가 몇 개인지를 return 하도록 solution 함수를 작성해주세요.
    //
    //
    //제한사항
    //노드의 개수 n은 2 이상 20,000 이하입니다.
    //간선은 양방향이며 총 1개 이상 50,000개 이하의 간선이 있습니다.
    //vertex 배열 각 행 [a, b]는 a번 노드와 b번 노드 사이에 간선이 있다는 의미입니다.
    class 가장_먼_노드
    {
        public int solution(int n, int[,] edge)
        {
            int[] dist = new int[n + 1];
            bool[,] map = new bool[n + 1,n + 1];
            for (int i = 0; i < edge.GetLength(0); i++)
            {
                map[edge[i,0],edge[i,1]] = map[edge[i,1],edge[i,0]] = true;
            }

            Queue < int > nodes = new Queue<int>();
            nodes.Enqueue(1);

            // BFS 탐색
            int maxDist = 0;
            while (!(nodes.Count == 0))
            {
                int i = nodes.Dequeue();

                for (int j = 2; j <= n; j++)
                {
                    if (dist[j] == 0 && map[i,j])
                    {
                        dist[j] = dist[i] + 1;
                        nodes.Enqueue(j);
                        maxDist = Math.Max(maxDist, dist[j]);
                    }
                }
            }

            // 가장 멀리 있는 노드가 몇 개인지 계산
            int count = 0;
            foreach (int d in dist)
            {
                if (maxDist == d)
                    count++;
            }

            return count;

        }


        public int solution1(int n, int[,] edge)
        {
            int[][] scores = new int[n + 1][];

            for (int i = 1; i <= n; i++)
            {
                scores[i] = new int[n + 1];
                for (int j = 1; j <= n; j++)
                {
                    scores[i][j] = i == j ? 0 : 987654321;
                }
            }

            for (int i = 0; i < edge.GetLength(0); i++)
            {
                int a = edge[i, 0];
                int b = edge[i, 1];
                scores[a][b] = 1;
                scores[b][a] = 1;
            }

            for (int a = 1; a <= n; a++)
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= n; j++)
                    {
                        if (i != j && j != a && i != a)
                        {
                            scores[i][j] = Math.Min(scores[i][j], scores[i][a] + scores[a][j]);
                        }
                    }
                }
            }

            int maxDis = 0;
            int count = 0;
            for (int j = 1; j <= n; j++)
            {
                if (1 == j) continue;
                if (scores[1][j] != 987654321)
                {
                    if (maxDis < scores[1][j])
                    {
                        maxDis = scores[1][j];
                        count = 1;
                    }
                    else if (maxDis == scores[1][j])
                    {
                        count++;
                    }
                }
            }
            return count;
        }
    }
}
