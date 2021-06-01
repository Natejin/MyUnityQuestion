using NateJin;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit
{
    public static class Greedy_Algorithms
    {
        static int minimumAbsoluteDifference(int[] arr)
        {
            int minimum = 2147483647;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                for (int j = 1; j < arr.Length; j++)
                {
                    int abs = Math.Abs(arr[j] - arr[i]);
                    if (minimum > abs)
                    {
                        minimum = abs;
                    }
                }
            }
            return minimum;
        }

        static int minimumAbsoluteDifference1(int[] arr)
        {
            Array.Sort(arr);
            int minimum = 0;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                int abs = Math.Abs(arr[i] - arr[i + 1]);
                if (minimum > abs)
                {
                    minimum = abs;
                }
            }
            return minimum;
        }


        static int luckBalance(int k, int[][] contests)
        {
            int[] tempArray = new int[contests.Length];
            int luckbalence = 0;
            int curr = 0;
            int importantCount = 0;
            for (int i = 0; i < contests.Length; i++)
            {
                if (contests[i][1] == 1)
                {
                    Console.WriteLine("important: " + contests[i][0]);
                    tempArray[curr++] = contests[i][0];
                    importantCount++;
                }
                else {
                    Console.WriteLine("Not important: " + contests[i][0]);
                    luckbalence += contests[i][0];
                }
            }

            int[] importantArray = new int[importantCount];
            Array.Copy(tempArray, 0, importantArray, 0, importantCount);
            Array.Sort(importantArray);

            int removeCount =  importantCount - k;
            Console.WriteLine("importantCount: " + importantCount + " removeCount: " + removeCount);
            for (int i = 0; i < importantCount; i++)
            {
                if (removeCount > 0)
                {
                    luckbalence -= importantArray[i];
                    Console.WriteLine("removeCount: " + importantArray[i] + " LuckyBalence: " + luckbalence);
                    removeCount--;
                }
                else {
                    luckbalence += importantArray[i];
                    Console.WriteLine("addCount: " + importantArray[i] + " LuckyBalence: " + luckbalence);
                }
            }

            return luckbalence;
        }

        static int luckBalance1(int k, int[][] contests)
        {
            int totalLuckBalance = 0;
            int impContestCount = 0;
            List<int> tempList = new List<int>();

            for (int i = 0; i < contests.Length; i++)
            {
                if (contests[i][1] == 0)
                    totalLuckBalance += contests[i][0];
                else
                {
                    impContestCount++;
                    tempList.Add(contests[i][0]);
                    totalLuckBalance += contests[i][0];
                }
            }

            if (impContestCount > k)
            {
                tempList.Sort();
                int n = impContestCount - k;
                for (int j = 0; j < n; j++)
                {
                    totalLuckBalance -= 2 * tempList[j];
                }
            }

            return totalLuckBalance;
        }

        static int getMinimumCost(int k, int[] c)
        {
            Array.Sort(c);
            int total = 0;
            int priceCount = 1;
            int partOfSetCounr = 0;
            for (int i = c.Length; i >= 0; i--)
            {
                if (k == partOfSetCounr)
                {
                    partOfSetCounr = 1;
                    priceCount++;
                }
                else {
                    partOfSetCounr++;
                }
                total += c[i] * (priceCount);

            }
            return total;
        }

        static int maxMin(int k, int[] arr)
        {
            Array.Sort(arr);
            int maxMin = 2147483647;
            int length = arr.Length - k + 1;
            for (int i = 0, j = k - 1; i < length; i++, j++)
            {
                int diff = arr[j] - arr[i];
                if (maxMin > diff)
                {
                    maxMin = diff;
                }
            }
            return maxMin;
        }

        public static string reverseShuffleMerge(string s)
        {
            float[] storeArr = new float[26];
            float[] remainArr = new float[26];

            for (int i = 0; i < s.Length; i++)
            {
                storeArr[s[i] - 97] += 0.5f;
            }

            for (int i = 0; i < storeArr.Length; i++)
            {
                if (storeArr[i] > 0)
                {
                    Console.WriteLine((char)(i + 97) + ": " + storeArr[i]);
                }
             
            }

            string answer = "";
            int currentExist = 0;
            Array.Copy(storeArr, remainArr, 26);
            while (remainArr[currentExist] == 0)
            {
                currentExist++;
            }

            int maxLength = s.Length / 2;
            for (int i = s.Length - 1; i >= 0; i--)
            {
                Console.WriteLine(s[i] + " store:  " + storeArr[s[i] - 97] + "| remain: " + remainArr[s[i] - 97] + "| currentExist : " + (char)(currentExist + 97) + "| answer: " + answer);
                if (currentExist == s[i] - 97)
                {
                    storeArr[currentExist]--;
                    remainArr[currentExist]--;
                    answer += s[i];
                }
                else {
                    if (storeArr[s[i] - 97] > 0)
                    {
                        storeArr[s[i] - 97]--;
                    }
                    else {
                        if (remainArr[s[i] - 97] > 0)
                        {
                            answer += s[i];
                            remainArr[s[i] - 97]--;
                        }

                    }
                }


                if (i == 0 || answer.Length == maxLength)
                {
                    break;
                }


                while ((remainArr[currentExist] == 0 || storeArr[currentExist] == 0) && currentExist < 25)
                {
                    currentExist++;
                }

                Console.WriteLine(s[i] + " store:  " + storeArr[s[i] - 97] + "| remain: " + remainArr[s[i] - 97] + "| currentExist : " + (char)(currentExist + 97) + "| answer: " + answer);

                Console.WriteLine();
            }


            return answer;
        }

        public static string reverseShuffleMerge1(string s)
        {
            int[] storeArr = new int[26];
            int[] skipArr = new int[26];
            Stack<char> chars_stack = new Stack<char>();

            int length = s.Length;
            for (int i = 0; i < s.Length; i++)
            {
                storeArr[s[i] - 'a']++;
            }

            for (int i = 0; i < 26; i++)
            {
                storeArr[i] /= 2;
            }

            Array.Copy(storeArr, skipArr, 26);


            for (int i = length - 1; i >= 0; i--)
            {
                while (!chars_stack.Empty() && chars_stack.Peek() > s[i] && storeArr[s[i] - 'a'] > 0 && skipArr[chars_stack.Peek() - 'a'] > 0)
                {
                    char c = chars_stack.Pop();
                    storeArr[c - 'a']++;
                    skipArr[c - 'a']--;
                }

                if (storeArr[s[i] - 'a'] > 0)
                {
                    chars_stack.Push(s[i]);
                    storeArr[s[i] - 'a']--;
                }
                else
                {
                    skipArr[s[i] - 'a']--;
                }
            }
            var temp = chars_stack.ToArray();
            Array.Reverse(temp);

            return new string(temp);
        }
    }
}
