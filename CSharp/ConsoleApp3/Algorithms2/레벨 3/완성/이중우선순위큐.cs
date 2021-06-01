using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    class 이중우선순위큐
    {
      

        public int[] solution(string[] arguments)
        {
            List<int> list = new List<int>();
            foreach (string cmd in arguments)
            {
                string[] str = cmd.Split(' ');
                if (str[0].Equals("I")) list.Add(int.Parse(str[1]));
                else if (list.Count() > 0 && str[1] == "1") list.Remove(list.Max());
                else if (list.Count() > 0 && str[1] == "-1") list.Remove(list.Min());
            }
            return list.Count() == 0 ? new int[] { 0, 0 } : new int[] { list.Max(), list.Min() };
        }

        public int[] solution1(string[] operations)
        {
            int[] answer = new int[2] {0,0 };
            List<int> list = new List<int>(); 
            for (int i = 0; i < operations.Length; i++)
            {
                var convert = operations[i].Split(" ");
                if (convert[0] == "I")
                {
                    list.Add(Convert.ToInt32(convert[1]));
                }
                else if(list.Count > 0){
                    if (Convert.ToInt32(convert[1]) == 1)
                    {
                        list = list.OrderBy(x => x).ToList();
                        list.Remove(list[list.Count - 1]);
                    }
                    else {
                        list = list.OrderBy(x => x).ToList();
                        list.Remove(list[0]);
                    }                
                }

            }
            list = list.OrderBy(x => x).ToList();
            if (list.Count > 1)
            {
                answer[0] = list[0];
                answer[1] = list[list.Count - 1];
            }
            else if(list.Count == 1) {
                answer[0] = list[0];
                answer[1] = list[0];
            }
           
            return answer;
        }
    }
}
