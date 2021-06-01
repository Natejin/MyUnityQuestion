using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation
{
    class Migratory_Birds
    {
        static int migratoryBirds(List<int> arr)
        {
            SortedDictionary<int, int> birdDic = new SortedDictionary<int, int>();
            for (int i = 0; i < arr.Count; i++)
            {
                if (birdDic.ContainsKey(arr[i]))
                {
                    birdDic[arr[i]]++;
                }
                else
                {
                    birdDic.Add(arr[i], 1);
                }
            }
            var sortDic = birdDic.OrderBy(x => x.Value);

            int last = sortDic.ElementAt(birdDic.Count - 1).Value;
            int currentKey = sortDic.ElementAt(birdDic.Count - 1).Key;
            for (int i = birdDic.Count - 1; i >= 1; i++)
            {

                if (sortDic.ElementAt(i - 1).Value == sortDic.ElementAt(i).Value)
                {
                    currentKey = sortDic.ElementAt(i - 1).Key;
                }
                else {
                    return currentKey;
                }
            }
           
            return currentKey;

        }

        static int migratoryBirds1(List<int> arr)
        {
            Dictionary<int, int> birdDic = new Dictionary<int, int>();
            for (int i = 0; i < arr.Count; i++)
            {
                if (birdDic.ContainsKey(arr[i]))
                {
                    birdDic[arr[i]]++;
                }
                else {
                    birdDic.Add(arr[i], 1);
                }
            }

            int currentlyType = 1000000;
            int count = 0;
            foreach (var bird in birdDic)
            {
                if (bird.Value > count)
                {
                    count = bird.Value;
                    currentlyType = bird.Key;
                } else if (bird.Value == count) {
                    if (currentlyType > bird.Key)
                    {
                        currentlyType = bird.Key;
                    }
                }
            }

            return currentlyType;

        }

        //11
        //1 2 3 4 5 4 3 2 1 3 4
        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int arrCount = Convert.ToInt32(Console.ReadLine().Trim());

            List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

            int result = migratoryBirds(arr);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
