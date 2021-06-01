using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Graphs
{
    class Journey_to_the_Moon
    {
        // Complete the journeyToMoon function below.
        static long journeyToMoon(int n, int[][] astronaut)
        {
            var arr = astronaut.OrderBy(x => x[0]).ToArray();
            Dictionary<int, int> astronautGroup = new Dictionary<int, int>();
            Dictionary<int, List<int>> groupList = new Dictionary<int, List<int>>();
            int key = 0;
            for (int i = 0; i < astronaut.Length; i++)
            {
                if (!astronautGroup.ContainsKey(astronaut[i][0]) && !astronautGroup.ContainsKey(astronaut[i][1]))
                {
                    List<int> temp = new List<int>();
                    astronautGroup.Add(astronaut[i][0], key);
                    astronautGroup.Add(astronaut[i][1], key);
                    temp.Add(astronaut[i][0]);
                    temp.Add(astronaut[i][1]);
                    groupList.Add(key, temp);
                    key++;
                }
                else if (!astronautGroup.ContainsKey(astronaut[i][0]))
                {
                    astronautGroup.Add(astronaut[i][0], astronautGroup[astronaut[i][1]]);
                    groupList[astronautGroup[astronaut[i][1]]].Add(astronaut[i][0]);
                }
                else if (!astronautGroup.ContainsKey(astronaut[i][1])) {
                    astronautGroup.Add(astronaut[i][1], astronautGroup[astronaut[i][0]]);
                    groupList[astronautGroup[astronaut[i][0]]].Add(astronaut[i][1]);
                } else{
                    if (astronautGroup[astronaut[i][1]] != astronautGroup[astronaut[i][0]])
                    {
                        int tempkey = astronautGroup[astronaut[i][0]];
                        int removeKey = astronautGroup[astronaut[i][1]];
                        List<int> from = groupList[astronautGroup[astronaut[i][1]]];
                        List<int> to = groupList[tempkey];
                        int index = 0;
                      
                        while (from.Count > index)
                        {
                            astronautGroup[from[index]] = tempkey;
                            to.Add(from[index]);
                            index++;
                        }
                        groupList.Remove(removeKey);
                    }
                }
            }

            long sum = 0;
            long result = 0;
            long totalcount = n - astronautGroup.Keys.Count;
            for (int i = 0; i < totalcount; i++)
            {
                groupList.Add(key, new List<int>() { 1 });
                key++;
            }
            foreach (var size in groupList)
            {
                result += sum * size.Value.Count;
                sum += size.Value.Count;
            }
            
            return result;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] np = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(np[0]);

            int p = Convert.ToInt32(np[1]);

            int[][] astronaut = new int[p][];

            for (int i = 0; i < p; i++)
            {
                astronaut[i] = Array.ConvertAll(Console.ReadLine().Split(' '), astronautTemp => Convert.ToInt32(astronautTemp));
            }

            long result = journeyToMoon(n, astronaut);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
