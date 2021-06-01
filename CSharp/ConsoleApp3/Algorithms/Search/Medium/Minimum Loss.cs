using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Search.Medium
{
    class Minimum_Loss
    {
        static int minimumLoss1(long[] price)
        {
            int ans = 1111111111;
            for (int i = 0; i < price.Length - 1; i++)
            {

                for (int j = i + 1; j < price.Length; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    if (price[i] - price[j] < ans && price[i] >= price[j])
                    {
                        ans = (int)(price[i] - price[j]);
                    }
                }
            }
            return ans;
        }
        static long minimumLoss(long[] price)
        {
            Dictionary<long, List<int>> elementDic = new Dictionary<long, List<int>>();

            for (int i = 0; i < price.Length; i++)
            {
                if (elementDic.ContainsKey(price[i]))
                {
                    elementDic[i].Add(i);
                }
                else {
                    elementDic.Add(price[i], new List<int>() { i });
                }
            }

            var sortedKeys = elementDic.Keys.OrderByDescending(x=>x).ToList();

            long minimum = 1111111111111111111;
            for (int i = 0; i < sortedKeys.Count; i++)
            {
                if (sortedKeys[i] - sortedKeys[i+1] < minimum)
                {
                    int sellIndex = 0;
                    int buyIndex = 0;
                    var keySell = elementDic[sortedKeys[i]].OrderBy(x=>x).ToArray();
                    var keyBuy = elementDic[sortedKeys[i + 1]].OrderBy(x => x).ToArray();
                    int count = elementDic[sortedKeys[i]].Count;
                    while (sellIndex < count)
                    {
                        if (keySell[sellIndex] < keyBuy[buyIndex])
                        {
                            sellIndex++;
                        }
                        else {
                            minimum = sortedKeys[i] - sortedKeys[i + 1];
                        }
                    }
                }
            }
            return (int)minimum;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            long[] price = Array.ConvertAll(Console.ReadLine().Split(' '), priceTemp => Convert.ToInt64(priceTemp))
            ;
            long result = minimumLoss(price);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
