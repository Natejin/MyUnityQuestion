using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms2
{

    //문제 설명
    //n명의 권투선수가 권투 대회에 참여했고 각각 1번부터 n번까지 번호를 받았습니다.권투 경기는 1대1 방식으로 진행이 되/고, /만약 A    선수가 B 선수보다 실력이 좋다면 A 선수는 B 선수를 항상 이깁니다.심판은 주어진 경기 결과를 가지고 선/수들/의 순위를 매기려     합니다.하지만 몇몇 경기 결과를 분실하여 정확하게 순위를 매길 수 없습니다.
    //
    //선수의 수 n, 경기 결과를 담은 2차원 배열 results가 매개변수로 주어질 때 정확하게 순위를 매길 수 있는 선수의 수를 //return    하도록 solution 함수를 작성해주세요.
    //
    //제한사항
    //선수의 수는 1명 이상 100명 이하입니다.
    //경기 결과는 1개 이상 4,500개 이하입니다.
    //results 배열 각 행 [A, B] 는 A 선수가 B 선수를 이겼다는 의미입니다.
    //모든 경기 결과에는 모순이 없습니다.
    class 순위_문제
    {
        public int solution(int n, int[,] results)
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

            for (int i = 0; i < results.GetLength(0); i++)
            {
                int a = results[i, 0];
                int b = results[i, 1];
                scores[a][b] = 1;
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

            bool[] flag = new bool[n + 1];
            flag = Enumerable.Repeat(true, flag.Length).ToArray();
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j) continue;
                    if (scores[i][j] == 987654321)
                    {
                        if (scores[j][i] == 987654321)
                        {
                            flag[i] = false;
                            break;
                        }
                    }
                }
            }

            int cnt = 0;

            for (int i = 1; i <= n; i++)
            {
                if (flag[i]) cnt++;
            }

            return cnt;
        }
    }
}
