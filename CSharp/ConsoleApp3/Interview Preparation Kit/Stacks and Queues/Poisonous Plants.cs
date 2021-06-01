using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Stacks_and_Queues
{
    class Poisonous_Plants
    {

        static int poisonousPlants(int[] p) {
            int[] days = new int[p.Length];
            int min = p[0];
            int max = 0;
            Stack<int> s = new Stack<int>();

            s.Push(0);

            for (int i = 1; i < p.Length; i++)
            {
                if (p[i] > p[i - 1])
                    days[i] = 1;
                Console.WriteLine("min: {0} p[{1}]: {2}", min, i, p[i]);
                min = min < p[i] ? min : p[i];
                
                while (s.Count != 0 && p[s.Peek()] >= p[i])
                {
                    Console.WriteLine("s.Peek(): {0} days[{1}]: {2}, days[{0}]+1: {3}", s.Peek(), i, days[i], days[s.Peek()]+1);
                    if (p[i] > min)
                        days[i] = days[i] > days[s.Peek()] + 1 ? days[i] : days[s.Peek()] + 1;

                    s.Pop();
                }
                Console.WriteLine("max: {0} days[{1}]: {2}", min, i, days[i]);
                max = max > days[i] ? max : days[i];
                s.Push(i);
            }
            return max;
        }


        static int poisonousPlants2(int[] p)
        {
            bool plantDead = true;
            int[] plantArr = p;
            Stack<int> plantStack = new Stack<int>();
            int count = 0;
            int stacked = plantArr[0];
            while (plantDead)
            {

                plantDead = false;
                int index = 0;
                while (index < plantArr.Length)
                {
                    if (stacked >= plantArr[index])
                    {
                        stacked = plantArr[index];
                        index++;

                        continue;
                    }
                    else
                    {
                        break;
                    }

                }
                // Console.WriteLine("Count: {0}, length: {1}, index: {2}, stacked: {3}", count, plantArr.Length,index, stacked);
                if (index == plantArr.Length)
                {
                    index = 1;
                    //plantArr[0] = stacked;
                }
                else
                {
                    plantStack.Push(plantArr[index - 1]);
                }

                // Console.WriteLine("arr[0]: {0}", plantArr[0]);
                for (int i = index; i < plantArr.Length; i++)
                {
                    //Console.WriteLine("arr[{0}]: {1}", i, plantArr[i]);
                    if (i == 0)
                    {
                        if (stacked < plantArr[i])
                        {
                            //Console.WriteLine("Remove[{0}]: {1}", i, plantArr[i]);
                            continue;
                        };
                    }
                    else
                    {
                        if (plantArr[i - 1] < plantArr[i])
                        {
                            plantDead = true;
                            // Console.WriteLine("Remove[{0}]: {1}", i, plantArr[i]);
                            continue;
                        };
                    }
                    // Console.WriteLine("plantArr[{0}]: {1}", i, plantArr[i]);
                    plantStack.Push(plantArr[i]);

                }

                if (plantDead)
                {
                    int[] tempPlantArr = new int[plantStack.Count];
                    for (int i = plantStack.Count - 1; i >= 0; i--)
                    {
                        tempPlantArr[i] = plantStack.Pop();
                        //  Console.WriteLine(tempPlantArr[i]);
                    }
                    plantArr = tempPlantArr;
                    count++;
                }
                else
                {
                    return count;
                }
            }
            return count;
        }


        static int poisonousPlants3(int[] p)
        {
            bool plantDead = true;
            int[] plantArr = p;
            Stack<int> plantStack = new Stack<int>();
            int count = 0;
            while (plantDead)
            {
                // Console.WriteLine("Count: {0}", count);
                plantDead = false;
                plantStack.Push(plantArr[0]);
                for (int i = 1; i < plantArr.Length; i++)
                {
                    if (plantArr[i - 1] < plantArr[i])
                    {
                        plantDead = true;
                        //Console.WriteLine("Remove[{0}]: {1}",i, plantArr[i]);
                        continue;

                    };
                    // Console.WriteLine("plantArr[{0}]: {1}",i, plantArr[i]);
                    plantStack.Push(plantArr[i]);

                }

                if (plantDead)
                {
                    int[] tempPlantArr = new int[plantStack.Count];
                    for (int i = plantStack.Count - 1; i >= 0; i--)
                    {
                        tempPlantArr[i] = plantStack.Pop();
                        //  Console.WriteLine(tempPlantArr[i]);
                    }
                    plantArr = tempPlantArr;
                    count++;
                }
                else
                {
                    return count;
                }
            }
            return count;
        }

        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] p = Array.ConvertAll(Console.ReadLine().Split(' '), pTemp => Convert.ToInt32(pTemp))
            ;
            int result = poisonousPlants(p);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
