using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Stacks_and_Queues
{
    class Queues_A_Tale_of_Two_Stacks
    {
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());
            List<int[]> list = new List<int[]>();
            Queue<int> tempQueue = new Queue<int>();



            for (int tItr = 0; tItr < t; tItr++)
            {
                list.Add(Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp)));
                if (list[tItr][0] == 1)
                {
                    tempQueue.Enqueue(list[tItr][1]);
                }
                else if (list[tItr][0] == 2)
                {
                    if (tempQueue.Count > 0)
                        tempQueue.Dequeue();
                }
                else
                {
                    if (tempQueue.Count > 0)
                        textWriter.WriteLine(tempQueue.Peek());
                }
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
