using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Graphs
{
    class BFS_Shortest_Reach_in_a_Graph
    {
        static int[] SearchShortest(int numOfNodes, int numOfEdges, int[] graphFrom, int[] graphTo, int startIndex) {
            List<int>[] connect = new List<int>[numOfNodes + 1];
            int[] answer = new int[numOfNodes];
            bool[] seen = new bool[numOfNodes + 1];
            for (int i = 0; i < connect.Length; i++)
            {
                connect[i] = new List<int>();
            }

            for (int i = 0; i < numOfEdges; i++)
            {
                //Console.WriteLine("graphFrom: {0} graphTo: {1}", graphFrom[i], graphTo[i]);
                connect[graphFrom[i]].Add( graphTo[i]);
                connect[graphTo[i]].Add(graphFrom[i]);
            }

            Stack<int> next = new Stack<int>();
            next.Push(startIndex);
            int[] tempAns = new int[numOfNodes + 1];

            int level = 6;


            for (int i = 0; i < tempAns.Length; i++)
            {
                tempAns[i] = -1;
            }
            tempAns[startIndex] = -5;
            while (next.Count > 0)
            {
                Stack<int> thisLevel = new Stack<int>();

                while (next.Count > 0)
                {
                    thisLevel.Push(next.Pop());
                    //Console.WriteLine(thisLevel.Peek());
                }


                while (thisLevel.Count > 0)
                {
                    int currentNode = thisLevel.Pop();
                    //Console.WriteLine("currentNode: {0} level {1}", currentNode, level);
                    while (connect[currentNode].Count> 0)
                    {
                        int index = connect[currentNode].Count - 1;
                        //Console.WriteLine("connect: {0} count {1}" , connect[currentNode][index], index + 1);
                        if (!seen[connect[currentNode][index]])
                        {
                            next.Push(connect[currentNode][index]);
                            tempAns[connect[currentNode][index]] = level;
                            seen[connect[currentNode][index]] = true;
                        }
                        connect[currentNode].RemoveAt(index);
                        connect[connect[currentNode][index]].Remove(currentNode);
                    }
                }
                level += 6;
            }

            Array.Copy(tempAns, 1, answer, 0, startIndex - 1);
            Array.Copy(tempAns, startIndex + 1, answer, startIndex -1, numOfNodes - startIndex);
            return answer;
        }

        //2
        //4 2
        //1 2
        //1 3
        //1
        //3 1
        //2 3
        //2

        //output
        static void Maain(String[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);


            int queries = Convert.ToInt32(Console.ReadLine());


            for (int i = 0; i < queries; i++)
            {
                string[] graphNodesEdges = Console.ReadLine().Split(' ');
                int numOfNodes = Convert.ToInt32(graphNodesEdges[0]);
                int numOfEdges = Convert.ToInt32(graphNodesEdges[1]);

                int[] graphFrom = new int[numOfEdges];
                int[] graphTo = new int[numOfEdges];
                //Console.WriteLine("numOfEdges {0} numOfNodes {1}", numOfEdges, numOfNodes);
                for (int j = 0; j < numOfEdges; j++)
                {
                    string[] graphFromTo = Console.ReadLine().Split(' ');
                    //Console.WriteLine("graphFromTo {0} graphFromTo {1}", graphFromTo[0], graphFromTo[1]);
                    graphFrom[i] = Convert.ToInt32(graphFromTo[0]);
                    graphTo[i] = Convert.ToInt32(graphFromTo[1]);
                }
                int startIndex = Convert.ToInt32(Console.ReadLine());
                //Console.WriteLine("startIndex {0}", startIndex);
               
                int[] ans = SearchShortest(numOfNodes, numOfEdges, graphFrom, graphTo,  startIndex);
                textWriter.WriteLine(string.Join(" ", ans));
            }
            textWriter.Flush();
            textWriter.Close();
        }
    }
}
