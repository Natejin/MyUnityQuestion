using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    public class 섬_연결하기
    {

        //부모 노드를 찾는 함수
        int GetParent(int[] parent, int node)
        {
            if (parent[node] == node) return node;
            return parent[node] = GetParent(parent, parent[node]);
        }

        //부모 노드를 합치는 함수
        void UnionParent(int[] parent, int a, int b)
        {
            a = GetParent(parent, a);
            b = GetParent(parent, b);
            if (a < b) parent[b] = a;
            else parent[a] = b;
        }

        //같은 부모를 공유하는지 확인
        bool CheckShareParent(int[] parent, int a, int b)
        {
            a = GetParent(parent, a);
            b = GetParent(parent, b);
            if (a == b) return true;
            else return false;
        }

        public int solution(int n, int[,] costs)
        {
            int answer = 0;
            int[][] cost = new int[costs.GetLength(0)][];
            int[] parent = new int[n];

            //convert 2d array to jagged array
            for (int i = 0; i < costs.GetLength(0); i++)
            {
                cost[i] = new int[costs.GetLength(1)];
                for (int j = 0; j < costs.GetLength(1); j++)
                {
                    cost[i][j] = costs[i, j];
                }
            }
            var a = cost.OrderBy(x => x[2]).ToArray();

            for (int i = 0; i < parent.Length; i++)
            {
                parent[i] = i;
            }


            for (int i = 0; i < a.Length; i++)
            {
                if (!CheckShareParent(parent, a[i][0], a[i][1]))
                {
                    UnionParent(parent, a[i][0], a[i][1]);
                    answer += a[i][2];
                }
            }
            return answer;
        }
    }
}
