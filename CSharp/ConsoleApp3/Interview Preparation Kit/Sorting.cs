using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NateJin;

namespace ConsoleApp3.Interview_Preparation_Kit
{
    class Sorting
    {
        static void countSwaps(int[] a)
        {
            int count = 0;
            for (int i = 0; i < a.Length; i++)
            {

                for (int j = 0; j < a.Length - 1; j++)
                {
                    // Swap adjacent elements if they are in decreasing order
                    if (a[j] > a[j + 1])
                    {
                        a.Swap(j, j+ 1);
                        count++;
                    }
                }
            }
            Console.WriteLine("Array is sorted in " + count +" swaps");
            Console.WriteLine("First Element: " + a[0]);
            Console.WriteLine("Last Element: " + a[a.Length-1]);
        }

        static int maximumToys(int[] prices, int k)
        {
           prices = prices.OrderBy(x => x).ToArray();
            int toyCount = 0;
            int toyTotalPrice = 0 ;
            for (int i = 0; i < prices.Length; i++)
            {
                if (toyTotalPrice + prices[i] <= k)
                {
                    toyTotalPrice += prices[i];
                    toyCount++;
                }
                else {
                    break;
                }
            }
            return toyCount;
        }

        class Player
        {
            public String name;
            public int score;

            Player(String name, int score)
            {
                this.name = name;
                this.score = score;
            }
        }


        static int compare(Player a, Player b)
        {
            if (a.score > b.score) return -1;
            else if (a.score < b.score) return 1;
            else return a.name.CompareTo(b.name);
        }

        static int activityNotifications(int[] expenditure, int d)
        {
            int[] tempArray = new int[d];
            int count = 0;
            int length = 0;
            int divide = d / 2;
            if (d % 2 == 0)
            {
                length = expenditure.Length - divide;
                for (int i = divide; i < expenditure.Length - divide; i++)
                {
                    Array.Copy(expenditure, i - divide, tempArray, 0, d);
                    tempArray = tempArray.OrderBy(x => x).ToArray();
                    if (tempArray[divide] + tempArray[divide - 1] <= expenditure[i + divide])
                    {
                        count++;
                    }
                }
            }
            else
            {
                length = expenditure.Length - divide - 1;
                for (int i = divide; i < expenditure.Length - divide - 1; i++)
                {
                    Array.Copy(expenditure, i - divide, tempArray, 0, d);
                    tempArray = tempArray.OrderBy(x => x).ToArray();
                    if (tempArray[divide] * 2 <= expenditure[i + divide + 1])
                    {
                        count++;
                    }
                }
            }
            return count;
        }

        static int activityNotifications1(int[] expenditure, int d)
        {
            int[] tempArray = new int[d];
            int count = 0;
            int length = 0;
            int divide = d / 2;
            if (d % 2 == 0)
            {
                length = expenditure.Length - divide;
                for (int i = divide; i < length; i++)
                {
 
                    Array.Copy(expenditure, i - divide, tempArray, 0, d);
                    float midian = MySort.FindMedian(tempArray);
                    if (midian * 2 <= expenditure[i + divide])
                    {
                        count++;
                    }
                }
            }
            else
            {
                length = expenditure.Length - divide - 1;
                for (int i = divide; i < length; i++)
                {
                    Array.Copy(expenditure, i - divide, tempArray, 0, d);
                    float midian = MySort.FindMedian(tempArray);
                    if (midian * 2 <= expenditure[i + divide + 1])
                    {
                        count++;
                    }
                }
            }
            return count;
        }

        static int activityNotifications2(int[] expenditure, int d)
        {
            int[] tempArray = new int[d];

            SortedIntList a = new SortedIntList();

            int count = 0;
            int length = 0;
            int divide = d / 2;
            if (d % 2 == 0)
            {
                length = expenditure.Length - divide;
                for (int i = divide; i < length; i++)
                {
                    for (int j = i - divide; j < d; j++)
                    {
                        a.AddSorted(expenditure[j]);
                        
                    }
                    if (a[a.Count / 2] + a[a.Count / 2 - 1] <= expenditure[i + divide])
                    {
                        count++;
                    }
                }
            }
            else
            {
                length = expenditure.Length - divide - 1;
                for (int i = divide; i < length; i++)
                {
                    for (int j = i - divide; j < d; j++)
                    {
                        a.AddSorted(expenditure[j]);

                    }
                    if (a[a.Count / 2] * 2  <= expenditure[i + divide + 1])
                    {
                        count++;
                    }
                }
            }
            return count;
        }

        static int activityNotifications3(int[] expenditure, int d)
        {
            int noti = 0;
            int[] cntArr = new int[201];

            for (int i = 0; i < d; i++)
            {
                cntArr[expenditure[i]]++;
            }

            for (int i = d; i < expenditure.Length; i++)
            {
                double median = MySort.FindMedian(cntArr, d);

                if (2 * median <= expenditure[i])
                {
                    noti++;
                }

                cntArr[expenditure[i - d]]--;
                cntArr[expenditure[i]]++;
            }

            return noti;
        }


        static long countInversions(int[] arr)
        {
            int count = 0;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                for (int j = i+1; j < arr.Length; j++)
                {
                    if (arr[i] >= arr[j])
                    {
                        arr.Swap(i, j);
                        count++;
                    }
                }
            }
            return count;
        }

        public static long countInversions1(int[] arr)
        {
            return MySort.MergeSortCount(arr, 0, arr.Length - 1);
        }

      
       
        

        
       

    }
}


public class SortedIntList : List<int>
{
    public void AddSorted(int x)
    {
        int position = this.BinarySearch(x);
        if (position < 0)
        { position = ~position; }
        this.Insert(position, x);
    }
}