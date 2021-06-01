using NateJin;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Graphs
{
    class Find_the_nearest_clone
    {
        // Complete the findShortest function below.

        /*
         * For the unweighted graph, <name>:
         *
         * 1. The number of nodes is <name>Nodes.
         * 2. The number of edges is <name>Edges.
         * 3. An edge exists between <name>From[i] to <name>To[i].
         *
         */
        static int findShortest(int graphNodes, int[] graphFrom, int[] graphTo, long[] ids, int val)
        {
            List<int>[] map = new List<int>[graphNodes];
            Dictionary<int, int> distances = new Dictionary<int, int>();

            for (int i = 0; i < graphNodes; i++)
            {
                map[i] = new List<int>();
            }

            for (int i = 0; i < graphFrom.Length; i++)
            {
                map[graphFrom[i] - 1].Add(graphTo[i]);
                map[graphTo[i] - 1].Add(graphFrom[i]);
            }

            Queue<int> queue = new Queue<int>();
            for (int i = 0; i < ids.Length; i++)
            {
                if (ids[i] == val)
                {
                    queue.Enqueue(i + 1);
                    distances.Add(i + 1, 0);
                }
            }

            if (queue.Count < 2)
            {
                return -1;
            }
            HashSet<int> seen = new HashSet<int>();
            while (queue.Count > 0)
            {

                int current = queue.Dequeue();
                Console.WriteLine("current {0}", current);
                seen.Add(current);

                foreach (int node in map[current - 1])
                {
                    Console.WriteLine("current {0} node {1} ", current, node);
                    if (distances.ContainsKey(node) && !seen.Contains(node))
                    {
                        return distances[node] + distances[current] + 1;
                    }
                    else
                    {
                        queue.Enqueue(node);
                        distances.AddOrSet(node, distances[current] + 1);
                    }
                }
            }
            return -1;


        }

        static int findShortest1(int graphNodes, int[] graphFrom, int[] graphTo, long[] ids, int val)
        {
            List<int>[] map = new List<int>[graphNodes];
            Dictionary <int, int> distances = new Dictionary<int, int>();

            for (int i = 0; i < graphNodes; i++)
            {
                map[i] = new List<int>();
            }

            for (int i = 0; i < graphFrom.Length; i++)
            {
                map[graphFrom[i] - 1].Add(graphTo[i]);
                map[graphTo[i] - 1].Add(graphFrom[i]);
            }

            Queue<int> queue = new Queue<int>();
            for (int i = 0; i < ids.Length; i++)
            {
                if (ids[i] == val)
                {
                    queue.Enqueue(i + 1);
                    distances.Add(i + 1, 0);
                }
            }

            if (queue.Count < 2)
            {
                return -1;
            }
            HashSet<int> seen = new HashSet<int>();
            while (queue.Count > 0)
            {
                int current = queue.Dequeue();
                seen.Add(current);

                foreach (int node in map[current - 1])
                {
                    if (distances.ContainsKey(node) && !seen.Contains(node))
                    {
                        return distances[node] + distances[current] + 1;
                    }
                    else
                    {
                        queue.Enqueue(node);
                        distances.AddOrSet(node, distances[current] + 1);
                    }
                }
            }
            return -1;


        }
        //4 3
        //1 2
        //1 3
        //4 2
        //1 2 3 4
        //2
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] graphNodesEdges = Console.ReadLine().Split(' ');
            int graphNodes = Convert.ToInt32(graphNodesEdges[0]);
            int graphEdges = Convert.ToInt32(graphNodesEdges[1]);

            int[] graphFrom = new int[graphEdges];
            int[] graphTo = new int[graphEdges];

            for (int i = 0; i < graphEdges; i++)
            {
                string[] graphFromTo = Console.ReadLine().Split(' ');
                graphFrom[i] = Convert.ToInt32(graphFromTo[0]);
                graphTo[i] = Convert.ToInt32(graphFromTo[1]);
            }

            long[] ids = Array.ConvertAll(Console.ReadLine().Split(' '), idsTemp => Convert.ToInt64(idsTemp))
            ;
            int val = Convert.ToInt32(Console.ReadLine());

            int ans = findShortest(graphNodes, graphFrom, graphTo, ids, val);

            textWriter.WriteLine(ans);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
