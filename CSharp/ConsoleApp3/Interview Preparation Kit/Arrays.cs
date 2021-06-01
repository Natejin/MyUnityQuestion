using NateJin;
using System;

namespace ConsoleApp3.Interview_Preparation_Kit
{
    public static class Arrays
    {
        public static int hourglassSum(int[][] arr)
        {
            int highestSum = -2147483648;
            for (int i = 0; i < arr.Length - 2; i++)
            {

                for (int j = 0; j < arr[i].Length - 2; j++)
                {
                    int topHourglass = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
                    int middleHourglass = arr[i + 1][j + 1];
                    int btmHourglass = arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
                    int sumhourglass = topHourglass + middleHourglass + btmHourglass;
                    if (highestSum < sumhourglass)
                    {
                        highestSum = sumhourglass;
                    }
                }
            }
            return highestSum;
        }


        public static int[] rotLeft(int[] a, int d)
        {
            int[] temp = new int[a.Length];

            Array.Copy(a, d, temp, 0, a.Length - d);
            Array.Copy(a, 0, temp, a.Length - d, d);
            return temp;
        }

        public static void minimumBribes(int[] A)
        {
            int n = A.Length;
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (A[i] != (i + 1))
                {
                    if (((i - 1) >= 0) && A[i - 1] == (i + 1))
                    {
                        cnt++;
                      A.Swap(i, i - 1);
                    }
                    else if (((i - 2) >= 0) && A[i - 2] == (i + 1))
                    {
                        cnt += 2;
                        A[i - 2] = A[i - 1];
                        A[i - 1] = A[i];
                        A[i] = i + 1;
                    }
                    else
                    {
                        Console.WriteLine("Too chaotic");
                        return;
                    }
                }
            }
            Console.WriteLine("%d", cnt);
        }

        public static void minimumBribes1(int[] q)
        {
            int totalBribes = 0;

            int expectedFirst = 1;
            int expectedSecond = 2;
            int expectedThird = 3;

            for (int i = 0; i < q.Length; ++i)
            {
                Console.WriteLine("q[i]: " + q[i] + " i: " + i + " 1:" + expectedFirst + " 2:" + expectedSecond + " 3:" + expectedThird);
                if (q[i] == expectedFirst)
                {
                    expectedFirst = expectedSecond;
                    expectedSecond = expectedThird;
                    expectedThird++;
                }
                else if (q[i] == expectedSecond)
                {
                    totalBribes++;
                    expectedSecond = expectedThird;
                    expectedThird++;
                }
                else if (q[i] == expectedThird)
                {
                    totalBribes += 2;
                    expectedThird++;
                }
                else
                {
                    Console.WriteLine("Too chaotic");
                    return;
                }


            }
            Console.WriteLine(totalBribes);
        }

        public static int minimumSwaps(int[] arr)
        {
            int c = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (arr[i] != i + 1)
                {

                    int targetIndex = Array.FindIndex(arr, x => x == i + 1);
                    arr.Swap(i, targetIndex);
                    c++;
                }
            }
            return c;
        }

        public static int minimumSwaps1(int[] arr)
        {
            int i, c = 0, n = arr.Length;
            for (i = 0; i < n; i++)
            {
                if (arr[i] == (i + 1))
                    continue;
                arr.Swap(i, arr[i] - 1);
                c++;
                i--;
            }
            return c;
        }

        public static int minimumSwaps2(int[] arr)
        {
            int c = 0;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                if (arr[i] != i + 1)
                {
                    int temp = i;
                    for (int j = 1 + i; j < arr.Length; j++)
                    {
                        if (arr[temp] >= arr[j])
                        {
                            temp = j;
                        }
                    }
                    arr.Swap(i, temp);
                    c++;
                }
            }
            return c;
        }

        public static int minimumSwaps3(int[] arr)
        {
            int c = 0;
            DCF_minimumSwaps3(arr, 0, 0, ref c);
            return c;
        }

        public static void DCF_minimumSwaps3(int[] arr, int s, int e, ref int c)
        {
            int pivot = arr[s];
            int bs = s, be = e;
            while (s < e)
            {
                while (pivot <= arr[e] && s < e) e--;
                if (s > e) break;
                while (pivot >= arr[s] && s < e) s++;
                if (s > e) break;
                c++;
                arr.Swap(s, e);
            }

            arr.Swap(bs, s);

            if (bs < s) DCF_minimumSwaps3(arr, bs, s - 1, ref c);
            if (be > e) DCF_minimumSwaps3(arr, s + 1, be, ref c);
        }


        static long arrayManipulation(int n, int[][] queries)
        {
            long[] tempArr = new long[n];
            long max = 0;
            for (int i = 0; i < queries.Length; i++)
            {
                for (int k = queries[i][0] - 1; k < queries[i][1]; k++)
                {
                    tempArr[k] += queries[i][2];
                    if (i == queries.Length - 1)
                    {
                        if (max < tempArr[k])
                        {
                            max = tempArr[k];
                        }
                    }
                }

                if (i == queries.Length - 1)
                {
                    for (int k = 0; k < queries[i][0] - 1; k++)
                    {
                        if (max < tempArr[k])
                        {
                            max = tempArr[k];
                        }
                    }
                    for (int k = queries[i][1]; k < n; k++)
                    {
                        if (max < tempArr[k])
                        {
                            max = tempArr[k];
                        }
                    }
                }

            }

            return max;
        }
        static long arrayManipulation1(int n, int[][] queries)
        {
            long[] tempArr = new long[n];
            long max = 0;
            for (int i = 0; i < queries.Length; i++)
            {
                for (int k = queries[i][0] - 1; k < queries[i][1]; k++)
                {
                    tempArr[k] += queries[i][2];
                    if (i == queries.Length - 1)
                    {
                        if (max < tempArr[k])
                        {
                            max = tempArr[k];
                        }
                    }
                }

                if (i == queries.Length - 1)
                {
                    for (int k = 0; k < queries[i][0] - 1; k++)
                    {
                        if (max < tempArr[k])
                        {
                            max = tempArr[k];
                        }
                    }
                    for (int k = queries[i][1]; k < n; k++)
                    {
                        if (max < tempArr[k])
                        {
                            max = tempArr[k];
                        }
                    }
                }

            }

            return max;
        }
    }
}