using NateJin;
using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit
{
    public static class StringManipulation
    {
        public static int makeAnagram(string a, string b)
        {
            int[] aStore = new int[26];
            int[] bStore = new int[26];
            int count = 0;
            count = a.Length > b.Length ? b.Length : a.Length;
            for (int i = 0; i < count; i++)
            {
                aStore[char.ToUpper(a[i]) - 64]++;
                bStore[char.ToUpper(b[i]) - 64]++;
            }
            if (a.Length > b.Length)
            {
                for (int i = count; i < a.Length; i++)
                {
                    aStore[char.ToUpper(a[i]) - 64]++;
                }
            }
            else {
                for (int i = count; i < b.Length; i++)
                {
                    bStore[char.ToUpper(b[i]) - 64]++;
                }
            }

            
            for (int i = 0; i < 27; i++)
            {
                count += Math.Abs(aStore[i] - bStore[i]);
            }
            return count;
        }

        static int alternatingCharacters(string s)
        {
            char currentChar = s[0];
            int count = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == currentChar)
                {
                    if (currentChar == 'A')
                    {
                        currentChar = 'B';
                    }
                    else {
                        currentChar = 'A';
                    }
                }
                else {
                    count++;
                }
            }
            return count;

        }


        static string isValid(string s)
        {
            Dictionary<char, int> store = new Dictionary<char, int>();
            for (int i = 0; i < s.Length; i++)
            {
                store.PlusOrAdd(s[i]);
            }
            int firstNumberCount = 0;
            int firstNumber = -1;
            int secondNumberCount = 0;
            int secondNumber = -1;

            Dictionary<int, int> count = new Dictionary<int, int>();
            foreach (var item in store)
            {
                int value = item.Value;

                if (count.ContainsKey(value))
                {
                    count[value]++;
                    if (firstNumber == value)
                    {
                        firstNumberCount++;
                    }
                    else if (secondNumber == value)
                    {
                        secondNumberCount++;
                    }
                }
                else
                {
                    count.Add(value, 1);
                    if (firstNumber == -1)
                    {
                        firstNumber = value;
                        firstNumberCount++;
                    }
                    else if (secondNumber == -1)
                    {
                        secondNumber = value;
                        secondNumberCount++;
                    }
                    else {
                        return "NO";
                    }
                }


                if (count.Count > 2 || (firstNumberCount > 1 && secondNumberCount > 1))
                {
                    return "NO";
                }
            }
            if ((firstNumber == 1 && firstNumberCount == 1) || (secondNumber == 1 && secondNumberCount == 1) || (firstNumber == -1 || secondNumber == -1))
            {
                return "YES";
            }

            Console.WriteLine(firstNumber + "||" + secondNumber);
            if (Math.Abs(firstNumber - secondNumber) <= 1)
            {
                return "YES";
            }
            else
            {

                return "NO";
            }

        }

        static long substrCount(int n, string s)
        {
            long count = 0;
            bool passedMid = false;
            for (int i = 0; i < s.Length; i++)
            {
                passedMid = false;
                count++;
                int thisTimeCount = 1;
                for (int j = i + 1; j < s.Length; j++)
                {
                    if (s[j] == s[i])
                    {
                        if (passedMid == false)
                        {
                            thisTimeCount++;
                            count++;
                        }
                        else {
                            thisTimeCount--;
                            if (thisTimeCount == 0)
                            {
                                count++;
                                break;
                            }
                        }
                    }
                    else {
                        if (passedMid == false)
                        {
                            passedMid = true;
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            return count;
        }

        static int commonChild(string s1, string s2)
        {

            int countA = 0;
            int countB = 0;


            int startAt = 0;
            for (int i = 0; i < s1.Length; i++)
            {
                for (int j = startAt; j < s2.Length; j++)
                {
                    if (s1[i] == s2[j])
                    {
                        startAt = j+1;
                        countA++;
                    }
                }
            }

            startAt = 0;
            for (int i = 0; i < s2.Length; i++)
            {
                for (int j = startAt; j < s1.Length; j++)
                {
                    if (s2[i] == s1[j])
                    {
                        startAt = j + 1;
                        countB++;
                    }
                }
            }


            return Math.Max(countA, countB);

        }

        static int commonChildA(string s1, string s2)
        {
            char[] X = s1.ToCharArray();
            char[] Y = s2.ToCharArray();
            int m = X.Length;
            int n = Y.Length;

            int[,] L = new int[m + 1, n + 1];

            for (int i = 0; i <= m; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    if (i == 0 || j == 0)
                        L[i, j] = 0;
                    else if (X[i - 1] == Y[j - 1])
                        L[i, j] = L[i - 1, j - 1] + 1;
                    else
                        L[i, j] = Math.Max(L[i - 1, j], L[i, j - 1]);
                }
            }
            return L[m, n];
        }


    }


}
