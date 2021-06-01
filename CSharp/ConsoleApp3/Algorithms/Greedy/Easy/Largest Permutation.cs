using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace ConsoleApp3.Algorithms.Greedy.Easy
{
    class Largest_Permutation
    {
        static int[] largestPermutation(int k, int[] arr)
        {
            int n = arr.Length;
            int[] temp = new int[arr.Length+1];
            for (int i = 0; i < n; ++i)
                temp[arr[i]] = i;
            for (int i = 0, m = n; i < n && (k > 0); ++i, --m)
                if (arr[temp[m]] != arr[i])
                {
                    arr[temp[m]] = arr[i];
                    temp[arr[i]] = temp[m];
                    arr[i] = m;
                    --k;
                }
            return arr;
        }

        static int[] largestPermutation1(int k, int[] arr)
        {
            Dictionary<int, int> tempDic = new Dictionary<int, int>();
            var tempArr = arr.ToList();
            for (int i = 0; i < arr.Length; i++)
                tempDic.Add(arr[i], i);

            var answer = arr.OrderByDescending(x => x).ToList();


            int count = k;
            int LookingIndex = 0;
            while (count > 0 && LookingIndex < arr.Length)
            {

                if (tempArr[LookingIndex] != answer[LookingIndex])
                {
                    count--;
                    int index = tempDic[answer[LookingIndex]];
                    tempDic[answer[LookingIndex]] = tempDic[tempArr[LookingIndex]];
                    tempDic[tempArr[LookingIndex]] = index;

                    int temp = tempArr[LookingIndex];
                    tempArr[LookingIndex] = tempArr[index];
                    tempArr[index] = temp;
                    LookingIndex++;
                }
                else
                {
                    LookingIndex++;
                }
            }
            return tempArr.ToArray();

        }



      
        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nk[0]);

            int k = Convert.ToInt32(nk[1]);

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
            ;
            int[] result = largestPermutation(k, arr);

            textWriter.WriteLine(string.Join(" ", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
