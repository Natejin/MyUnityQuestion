using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Easy
{
    class Jim_and_the_Orders
    {
        static int[] jimOrders(int[][] orders)
        {
            int[][] tempArr = new int[orders.Length][];

            for (int i = 0; i < orders.Length; i++)
            {
                tempArr[i] = new int[2];
                tempArr[i][0] = orders[i][0] + orders[i][1];
                tempArr[i][1] = i + 1;
            }
            int[] answer = new int[orders.Length];
            var temparr = tempArr.OrderBy(x => x[0]).ToArray();

            for (int i = 0; i < temparr.Length; i++)
            {
                answer[i] = temparr[i][1];
            }
            
            return answer;
        }

        static int[] jimOrders1(int[][] orders)
        {
            Dictionary<int, List<int>> tempDic = new Dictionary<int, List<int>>();

            for (int i = 0; i < orders.Length; i++)
            {
                int temp = orders[i][0] + orders[i][1];
                if (tempDic.ContainsKey(temp))
                {
                    tempDic[temp].Add(i + 1);
                }
                else {
                    tempDic.Add(orders[i][0] + orders[i][1], new List<int>() { i+1});
                }
            }
            int[] answer = new int[orders.Length];
            var temparr = tempDic.Keys.OrderBy(x => x).ToArray();

            for (int i = 0, k =0; i < orders.Length; i++, k++)
            {
                for (int j = 0; j < tempDic[temparr[i]].Count;j++, k++)
                {
                    answer[k] = tempDic[temparr[i]][j];
                }
            }
            return answer;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[][] orders = new int[n][];

            for (int i = 0; i < n; i++)
            {
                orders[i] = Array.ConvertAll(Console.ReadLine().Split(' '), ordersTemp => Convert.ToInt32(ordersTemp));
            }

            int[] result = jimOrders(orders);

            textWriter.WriteLine(string.Join(" ", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
