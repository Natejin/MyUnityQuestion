using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Numerics;
using System.Text;
using NateJin.Vector2;

namespace ConsoleApp3.Interview_Preparation_Kit.Stacks_and_Queues
{
    class Castle_on_the_Grid
    {
        public class Node {
            public bool walkable;
            public bool scanned;
            public MyVec2Int pos;
            public int max;
            public int gCost;
            public int hCost;


            public Node(bool walkable, MyVec2Int pos, int max)
            {
                this.walkable = walkable;
                this.pos = pos;
                this.max = max;
                scanned = false;
               
            }

            public int fCost {
                get {
                    return gCost * hCost;
                }
            }

            public List<Node> GetNeighbours(MyVec2Int[] direct) {
                List<Node> tempList = new List<Node>();
                for (int i = 0; i < direct.Length; i++)
                {
                    MyVec2Int temp =  pos + direct[i];
                    if (temp.x == -1 || temp.x == max || temp.y == -1 || temp.y == max) continue;
                    tempList.Add(new Node(false, temp, max));
                }
                return tempList;
            }
        }



        public static MyVec2Int[] direct = new[] {  new MyVec2Int(0, 1), 
                                                    new MyVec2Int(0,-1), 
                                                    new MyVec2Int(-1,0), 
                                                    new MyVec2Int( 1,0)};

        public static int CalDistance(MyVec2Int first, MyVec2Int second) {
            return Math.Abs(first.x - second.x) + Math.Abs(first.y - second.y);
        }

        


        static int minimumMoves(string[] grid, int startX, int startY, int goalX, int goalY)
        {
            Node[,] mark = new Node[grid.Length, grid.Length];

            for (int i = 0; i < grid.Length; i++)
            {
                char[] charArr =  grid[i].ToCharArray();
                for (int j = 0; j < grid.Length; j++)
                {
                    mark[i, j] = new Node(charArr[j] == '.' ? true : false, new MyVec2Int(i, j), grid.Length);
                }
            }

            bool doneTrigger = false;
            Node startPos = new Node(true, new MyVec2Int( startX, startY), grid.Length);
            Node endNode = new Node(true, new MyVec2Int(goalX, goalY), grid.Length);
            List<Node> openSet = new List<Node>();
            HashSet<Node> closedSet = new HashSet<Node>();
            int count = 0;
            while (startPos.pos == endNode.pos)
            {



                //Node currentNode = openSet[0];
                //for (int i = 1; i < openSet.Count; i++)
                //{
                //    if (!openSet[i].walkable) continue;
                //    if (openSet[i].fCost < currentNode.fCost || openSet[i].fCost == currentNode.fCost && openSet[i].hCost < currentNode.hCost)
                //    {
                //        currentNode = openSet[i];

                //    }
                //}

                //openSet.Remove(currentNode);
                //closedSet.Add(currentNode);

                //if (currentNode == endNode) return count;
                //foreach (var neighbourNode in currentNode.GetNeighbours(direct))
                //{

                //}
            }


            //int count = 0;
            //bool previousXAxis = true;

            //while (!doneTrigger)
            //{
            //    if (startPos == endNode) break;
            //    int distanceVal = 20000000;
            //    MyVec2Int nextTarget;
            //    int index = 0;
            //    for (int i = 0; i < direct.Length; i++)
            //    {
            //        MyVec2Int temp = startPos.pos + direct[i];
            //        if (temp.x == -1 || temp.x == grid.Length || temp.y == -1 || temp.y == grid.Length) continue;
            //        if (!mark[temp.x, temp.y].walkable) continue;

            //        int tempDistance = CalDistance(startPos.pos, temp);
            //        if (tempDistance < distanceVal)
            //        {
            //            nextTarget = temp;
            //        } 


            //    }
            //}

            return 0;
        }

        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            string[] grid = new string[n];

            for (int i = 0; i < n; i++)
            {
                string gridItem = Console.ReadLine();
                grid[i] = gridItem;
            }

            string[] startXStartY = Console.ReadLine().Split(' ');

            int startX = Convert.ToInt32(startXStartY[0]);

            int startY = Convert.ToInt32(startXStartY[1]);

            int goalX = Convert.ToInt32(startXStartY[2]);

            int goalY = Convert.ToInt32(startXStartY[3]);

            int result = minimumMoves(grid, startX, startY, goalX, goalY);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
