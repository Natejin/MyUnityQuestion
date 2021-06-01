using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    //N개의 아파트가 일렬로 쭉 늘어서 있습니다. 이 중에서 일부 아파트 옥상에는 4g 기지국이 설치되어 있습니다.
    //기술이 발전해 5g 수요가 높아져 4g 기지국을 5g 기지국으로 바꾸려 합니다.
    //그런데 5g 기지국은 4g 기지국보다 전달 범위가 좁아, 4g 기지국을 5g 기지국으로 바꾸면 어떤 아파트에는 전파가 도달하지 않습니다.

    //예를 들어 11개의 아파트가 쭉 늘어서 있고, [4, 11] 번째 아파트 옥상에는 4g 기지국이 설치되어 있습니다.
    //만약 이 4g 기지국이 전파 도달 거리가 1인 5g 기지국으로 바뀔 경우 모든 아파트에 전파를 전달할 수 없습니다.
    //(전파의 도달 거리가 W일 땐, 기지국이 설치된 아파트를 기준으로 전파를 양쪽으로 W만큼 전달할 수 있습니다.)

    class 기지국_설치
    {
        public int solution(int n, int[] stations, int w)
        {
            int answer = 0;
            bool[] connectedAparts = new bool[n];

            for (int i = 0; i < stations.Length; i++)
            {
                for (int j = stations[i] - w; j <= stations[i] + w; j++)
                {
                    if (j >= 0 && j< stations.Length)
                    {
                        connectedAparts[i] = true;
                    }
                }
            }
            int maxnum = 2 * w + 1;
            for (int i = 0; i < n; i++)
            {
                if (connectedAparts[i]) continue;
                int currentlyNum = 0;
                while (currentlyNum < maxnum)
                {
                    if (connectedAparts[i + currentlyNum])
                    {
                        answer++;
                        break;
                    }
                    currentlyNum++;
                    
                }
                i += currentlyNum;
                if (currentlyNum == maxnum)
                {
                    answer++;
                }
            }
            // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
            System.Console.WriteLine("Hello C#");

            return answer;
        }

        public int solution2(int n, int[] stations, int w)
        {
            int answer = 0;
            int station = 0;
            int now = 1;
            while (now <= n)
            {
                if (station < stations.Length && now >= stations[station] - w)
                {
                    now = stations[station] + w + 1;
                    station++;
                }
                else
                {
                    now += w + w + 1;
                    answer++;
                }
            }
            return answer;
        }

        public int solution1(int n, int[] stations, int w) //시간 
        {
            int answer = 0;
            bool[] connect = new bool[n + 1];
            connect[0] = true;
            for (int i = 0; i < stations.Length; i++)
            {
                for (int j = stations[i] - w; j <= stations[i] + w; j++)
                {
                    if (j < 1) continue;
                    if (j > n) break;
                    connect[j] = true;
                }
            }
            // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
            System.Console.WriteLine("Hello C#");

            int count = 0;
            for (int i = 1; i <= n; i++)
            {
                if (connect[i] == false)
                {
                    count++;
                    continue;
                }
                else
                {
                    if (count > 0)
                    {
                        answer += (int)Math.Ceiling((float)count / (2 * w + 1));
                        count = 0;
                    }

                }
            }
            return answer;
        }

        public int solutin(int n, int[] stations, int w)
        {
            int answer = 0;
            int start = 0;
            int dis = w * 2 + 1;
            Array.Sort(stations);

            for (int i = 0; i < stations.Length; i++)
            {
                int left = stations[i] - 1 - w;
                int right = stations[i] - 1 + w;

                //기존 기지국이 겹쳐있을 경우
                if (start >= left && start <= right)
                {
                    start = right + 1;
                    continue;
                }

                int div = (left - start) / dis;
                int rest = (left - start) % dis;
                if (rest > 0)
                {
                    div += 1;
                }
                answer += div;
                //다음 시작지점
                start = right + 1;
            }
            //기존 기지국 중에 마지막 기지국 이후 N까지
            if (start < n)
            {
                int div = (n - start) / dis;
                int rest = (n - start) % dis;
                if (rest > 0)
                    div += 1;
                answer += div;
            }

            return answer;
        }
    }
}
