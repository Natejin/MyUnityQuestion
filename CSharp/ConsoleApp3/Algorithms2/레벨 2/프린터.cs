using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Collections;

namespace ConsoleApp3.Algorithms2.레벨_2
{
    //문제 설명

    //일반적인 프린터는 인쇄 요청이 들어온 순서대로 인쇄합니다.
    //그렇기 때문에 중요한 문서가 나중에 인쇄될 수 있습니다.이런 문제를 보완하기 위해
    //중요도가 높은 문서를 먼저 인쇄하는 프린터를 개발했습니다. 이 새롭게 개발한 프린터는
    //아래와 같은 방식으로 인쇄 작업을 수행합니다.
    //
    //1. 인쇄 대기목록의 가장 앞에 있는 문서(J) 를 대기목록에서 꺼냅니다.
    //2. 나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 한 개라도 존재하면 J를 대기목록의 가장 마지막에 넣습니다.
    //3. 그렇지 않으면 J를 인쇄합니다.
    //예를 들어, 4개의 문서(A, B, C, D) 가 순서대로 인쇄 대기목록에 있고 중요도가 2 1 3 2 라면 C D A B 순으로 인쇄하게 됩니다.
    //
    //
    //내가 인쇄를 요청한 문서가 몇 번째로 인쇄되는지 알고 싶습니다.
    //위의 예에서 C는 1번째로, A는 3번째로 인쇄됩니다.
    //
    //
    //현재 대기목록에 있는 문서의 중요도가 순서대로 담긴 배열 priorities와
    //내가 인쇄를 요청한 문서가 현재 대기목록의 어떤 위치에 있는지를 알려주는
    //location이 매개변수로 주어질 때, 내가 인쇄를 요청한 문서가 몇 번째로
    //인쇄되는지 return 하도록 solution 함수를 작성해주세요.
    //
    //
    //제한사항

    //현재 대기목록에는 1개 이상 100개 이하의 문서가 있습니다.
    //인쇄 작업의 중요도는 1~9로 표현하며 숫자가 클수록 중요하다는 뜻입니다.
    //location은 0 이상 (현재 대기목록에 있는 작업 수 - 1) 이하의
    //값을 가지며 대기목록의 가장 앞에 있으면 0, 두 번째에 있으면 1로 표현합니다.

    //입출력 예
    //priorities            location    return
    //[2, 1, 3, 2]          2	        1
    //[1, 1, 9, 1, 1, 1]    0	        5

    //입출력 예 설명

    //예제 #1
    //
    //문제에 나온 예와 같습니다.
    //
    //예제 #2
    //
    //6개의 문서(A, B, C, D, E, F) 가 인쇄 대기목록에 있고 중요도가 1 1 9 1 1 1 이므로 C D E F A B 순으로 인쇄합니다.


    class 프린터
    {


        public int solution(int[] priorities, int location)
        {
            List<int> list = priorities.ToList();
            List<int> order = new List<int>();

            for (int i = 0; i < list.Count; i++)
            {
                order.Add(i + 1);
            }

            for (int i = 0; i < list.Count; i++)
            {
                for (int j = i + 1; j < list.Count; j++)
                {
                    if (list[i] < list[j])
                    {
                        int prior = list[i];
                        list.RemoveAt(i);
                        list.Add(prior);

                        prior = order[i];
                        order.RemoveAt(i);
                        order.Add(prior);

                        i--;
                        break;
                    }
                }
            }

            var tempLoc = location + 1;
            for (int i = 0; i < order.Count; i++)
            {
                if (tempLoc == order[i])
                {
                    return i + 1;
                }
            }
            return -1;
        }
        struct Data
        {
            public int index;
            public int val;

            public Data(int index, int val)
            {
                this.index = index;
                this.val = val;
            }
        }





        public int solution2(int[] priorities, int location)
        {
            int answer = 0;

            Queue queue = new Queue();
            int index = 0;
            foreach (int i in priorities)
                queue.Enqueue(index++ + "," + i);

            while (queue.Count != 0)
            {
                string[] q_split = queue.Dequeue().ToString().Split(',');
                int q_index = int.Parse(q_split[0]);
                int value = int.Parse(q_split[1]);

                if (check(value, priorities))
                    queue.Enqueue(q_index + "," + value);
                else
                {
                    answer++;
                    priorities[q_index] = -1;
                    if (q_index == location)
                        break;
                }
            }

            return answer;
        }
        public bool check(int value, int[] priorities)
        {
            foreach (int i in priorities)
                if (value < i) return true;
            return false;
        }


        public int solution3(int[] priorities, int location)
        {
            int lastPrintIndex = -1;
            System.Collections.Generic.List<int> order = new System.Collections.Generic.List<int>();
            for (int i = 9; i > 0; --i)
            {
                //시작인덱스에 +1를 설정(현재 인덱스는 마지막으로 찾은 수의 인덱스 이므로)
                int nextPrintIndex = lastPrintIndex + 1;
                for (int j = 0; j < priorities.Length; ++j)
                {

                    int checkIndex = (nextPrintIndex + j) % priorities.Length;
                    if (priorities[checkIndex] == i)
                    {
                        order.Add(checkIndex);

                        //다음 값의 시작인덱스를 현재 값의 가장 뒤에있는 인덱스로 설정
                        lastPrintIndex = checkIndex;
                    }
                }
            }

            for (int i = 0; i < order.Count; ++i)
            {
                if (order[i] == location)
                {
                    return i + 1;
                }
            }

            return -1;
        }
    }
}


