using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;

using System.Text;

namespace NateJin
{
    public static class Support
    {

        #region Array
        public static void SortAndDistinct(this int[] arr)
        {
            Array.Sort(arr);
            arr = arr.Distinct().ToArray();
        }

        public static void Swap<T>(this T[] arr, int a, int b)
        {
            T temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }

        public static void Swap<T>(T a, T b)
        {
            T temp = a;
            a = b;
            b = temp;
        }


        #endregion

        #region 2D-Array
        public static void SortDoubleDimension<T>(T[,] array, bool bySecond = false)
        {
            int length = array.GetLength(0);
            T[] dim1 = new T[length];
            T[] dim2 = new T[length];
            for (int i = 0; i < length; i++)
            {
                dim1[i] = array[i, 0];
                dim2[i] = array[i, 1];
            }
            if (bySecond) Array.Sort(dim2, dim1);
            else Array.Sort(dim1, dim2);
            for (int i = 0; i < length; i++)
            {
                array[i, 0] = dim1[i];
                array[i, 1] = dim2[i];
            }
        }

        public static void SortThisDoubleDimension<T>(this T[,] array, bool bySecond = false)
        {
            int length = array.GetLength(0);
            T[] dim1 = new T[length];
            T[] dim2 = new T[length];
            for (int i = 0; i < length; i++)
            {
                dim1[i] = array[i, 0];
                dim2[i] = array[i, 1];
            }
            if (bySecond) Array.Sort(dim2, dim1);
            else Array.Sort(dim1, dim2);
            for (int i = 0; i < length; i++)
            {
                array[i, 0] = dim1[i];
                array[i, 1] = dim2[i];
            }
        }
        #endregion

        #region SortedSet
        //The true workhorse of the code!
        public static T ElementBefore<T>(this SortedSet<T> mySet, T val, IComparer<T> comparer)
        {
            //we are getting the first element el such that it is before
            //the provided value val. We must reverse the set because
            //otherwise, the first element in the set is always the first
            //to be less than the provided value.
            return mySet.Reverse().FirstOrDefault(el => comparer.Compare(el, val) < 0);
        }

        //Contains all the actual logic
        public static T ElementAfter<T>(this SortedSet<T> mySet, T val, IComparer<T> comparer)
        {
            //we are getting the first element el such that it is after
            //the provided value val.
            return mySet.FirstOrDefault(el => comparer.Compare(el, val) > 0);
        }

        //use the existing logic, but use the default comparer for the set
        public static T ElementBefore<T>(this SortedSet<T> mySet, T val)
        {
            return ElementBefore(mySet, val, mySet.Comparer);
        }

        //use the existing logic, but use the default comparer for the set
        public static T ElementAfter<T>(this SortedSet<T> mySet, T val)
        {
            return ElementAfter(mySet, val, mySet.Comparer);
        }

        //provide a condition that the element must already exist in the set
        //Consider a set of strings containing only "apple" and "cat"
        //without forcing the element to exist in the set, we could search for
        //the element before "bear" and get "apple" even though "bear" is not
        //in the set. Forcing the element to exist by setting mustExist=true
        //would return null if the element is not there already


        //provide a condition that the element must already exist in the set
        //Consider a set of strings containing only "apple" and "cat"
        //without forcing the element to exist in the set, we could search for
        //the element after "bear" and get "cat" even though "bear" is not
        //in the set. Forcing the element to exist by setting mustExist=true
        //would return null if the element is not there already
        public static T ElementBefore<T>(this SortedSet<T> mySet, T val, bool mustExist, IComparer<T> comparer)
        {

            if (mustExist)
            {
                if (mySet.Contains(val))
                {
                    //take advantage of existing logic
                    return ElementAfter(mySet, val, comparer);
                }
                else
                {
                    return default;
                }
            }
            else
            {
                //take advantage of existing logic
                return ElementAfter(mySet, val, comparer);
            }
        }

        public static T ElementAfter<T>(this SortedSet<T> mySet, T val, bool mustExist, IComparer<T> comparer)
        {

            if (mustExist)
            {
                if (mySet.Contains(val))
                {
                    //take advantage of existing logic
                    return ElementAfter(mySet, val, comparer);
                }
                else
                {
                    return default;
                }
            }
            else
            {
                //take advantage of existing logic
                return ElementAfter(mySet, val, comparer);
            }
        }

        //just use the default set comparer
        public static T ElementBefore<T>(this SortedSet<T> mySet, T val, bool mustExist)
        {
            //take advantage of existing logic
            return ElementBefore(mySet, val, mustExist, mySet.Comparer);
        }

        //just use the default set comparer
        public static T ElementAfter<T>(this SortedSet<T> mySet, T val, bool mustExist)
        {
            //take advantage of existing logic
            return ElementAfter(mySet, val, mustExist, mySet.Comparer);
        }
        #endregion


        #region Dictionary
        public static void CloneDictionary<TKey, TValue>(this Dictionary<TKey, TValue> sorceDic, Dictionary<TKey, TValue> originalDic) where TValue : ICloneable
        {
            foreach (KeyValuePair<TKey, TValue> entry in originalDic)
            {
                sorceDic.Add(entry.Key, (TValue)entry.Value.Clone());
            }
        }

        public static void CopyDictionary<TKey, TValue>(this Dictionary<TKey, TValue> sorceDic, Dictionary<TKey, TValue> originalDic) where TValue : struct
        {
            foreach (KeyValuePair<TKey, TValue> entry in originalDic)
            {
                sorceDic.Add(entry.Key, entry.Value);
            }
        }


        public static void PlusOrAdd<T1>(this Dictionary<T1, int> dic, T1 key)
        {
            if (!dic.ContainsKey(key))
            {
                dic.Add(key, 1);
            }
            else
            {
                dic[key]++;
            }
        }

        public static void SubOrRemove<T1>(this Dictionary<T1, int> dic, T1 key)
        {
            if (dic.ContainsKey(key))
            {
                if (dic[key] > 1)
                {
                    dic[key]--;
                }
                else
                {
                    dic.Remove(key);
                }
            }
        }

        public static void AddCountToDic<T>(this Dictionary<T, int> dic, T key)
        {
            if (dic.ContainsKey(key))
            {
                dic[key]++;
            }
            else
            {
                dic.Add(key, 1);
            }
        }

        public static TValue AddThenReturn<TKey, TValue>(this Dictionary<TKey, TValue> dic, TKey key, TValue value)
        {
            if (dic.ContainsKey(key))
                dic[key] = value;
            else
                dic.Add(key, value);
            return value;
        }

        public static bool TryAddOrSet<TKey, TValue>(this Dictionary<TKey, TValue> dic, TKey key, TValue value)
        {
            if (dic.ContainsKey(key))
            {
                dic[key] = value;
                return true;
            }
            else
            {
                dic.Add(key, value);
                return false;
            }
        }

        public static void AddOrSet<TKey, TValue>(this Dictionary<TKey, TValue> dic, TKey key, TValue value)
        {
            if (dic.ContainsKey(key))
                dic[key] = value;
            else
                dic.Add(key, value);
        }

        public static bool PlusOrAdd<T1>(this Dictionary<T1, float> dic, T1 key)
        {
            if (!dic.ContainsKey(key))
            {
                dic.Add(key, 1);
                return true;
            }
            else
            {
                dic[key]++;
                return false;
            }
        }

        public static bool SubOrRemove<T1>(this Dictionary<T1, float> dic, T1 key)
        {
            if (dic.ContainsKey(key))
            {
                if (dic[key] != 1)
                {
                    dic[key]--;
                    return true;
                }
                else
                {
                    dic.Remove(key);
                    return false;
                }
            }
            return false;
        }

        public static void PlusOrAdd<T1>(this Dictionary<T1, long> dic, T1 key)
        {
            if (!dic.ContainsKey(key))
            {
                dic.Add(key, 1);
            }
            else
            {
                dic[key]++;
            }
        }

        public static void SubOrRemove<T1>(this Dictionary<T1, long> dic, T1 key)
        {
            if (dic.ContainsKey(key))
            {
                if (dic[key] > 1)
                {
                    dic[key]--;
                }
                else
                {
                    dic.Remove(key);
                }
            }
        }
        public static TValue GetOrDefault<TKey, TValue>(this Dictionary<TKey, TValue> dic, TKey key, TValue value)
        {
            if (!dic.ContainsKey(key))
            {
                dic.Add(key, value);
            }

            return dic[key];
        }

        public static bool AddIfEmpty<TKey, TValue>(this Dictionary<TKey, TValue> dic, TKey key, TValue value)
        {
            if (!dic.ContainsKey(key))
            {
                dic.Add(key, value);
                return true;
            }

            return false;
        }
        #endregion


        #region SortedList

        public static int BinarySearch<TKey, TValue>(this SortedList<TKey, TValue> sortedList, TKey keyToFind, IComparer<TKey> comparer = null)
        {
            // need to create an array because SortedList.keys is a private array
            var keys = sortedList.Keys;
            TKey[] keyArray = new TKey[keys.Count];
            for (int i = 0; i < keyArray.Length; i++)
                keyArray[i] = keys[i];

            if (comparer == null) comparer = Comparer<TKey>.Default;
            int index = Array.BinarySearch<TKey>(keyArray, keyToFind, comparer);
            return index;
        }

        public static IEnumerable<TKey> GetKeyRangeBetween<TKey, TValue>(this SortedList<TKey, TValue> sortedList, TKey low, TKey high, IComparer<TKey> comparer = null)
        {
            int lowIndex = sortedList.BinarySearch(low, comparer);
            if (lowIndex < 0)
            {
                // list doesn't contain the key, find nearest behind
                // If not found, BinarySearch returns the complement of the index
                lowIndex = ~lowIndex;
            }

            int highIndex = sortedList.BinarySearch(high, comparer);
            if (highIndex < 0)
            {
                // list doesn't contain the key, find nearest before
                // If not found, BinarySearch returns the complement of the index
                highIndex = ~highIndex - 1;
            }

            var keys = sortedList.Keys;
            for (int i = lowIndex; i < highIndex; i++)
            {
                yield return keys[i];
            }
        }
        #endregion


        #region Bit
        public static int LeadingZeros(int x)
        {
            const int numIntBits = sizeof(int) * 8; //compile time constant
                                                    //do the smearing
            x |= x >> 1;
            x |= x >> 2;
            x |= x >> 4;
            x |= x >> 8;
            x |= x >> 16;
            //count the ones
            x -= x >> 1 & 0x55555555;
            x = (x >> 2 & 0x33333333) + (x & 0x33333333);
            x = (x >> 4) + x & 0x0f0f0f0f;
            x += x >> 8;
            x += x >> 16;
            return numIntBits - (x & 0x0000003f); //subtract # of 1s from 32
        }
        #endregion



        public static int[] MakeInt32Array(string a)
        {
            return a.Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
        }

        public static long[] MakeInt64Array(string a)
        {
            return a.Split(' ').Select(n => Convert.ToInt64(n)).ToArray();
        }

        public static List<int> MakeInt32List(string a)
        {
            return a.Split(' ').Select(n => Convert.ToInt32(n)).ToList();
        }

        public static List<long> MakeInt64List(string a)
        {
            return a.Split(' ').Select(n => Convert.ToInt64(n)).ToList();
        }

        public static int[][] MakeArray(string a, int index, int jndex)
        {
            var temp = a.Split(' ').Select(n => Convert.ToInt32(n)).ToArray();
            int[][] temparray = new int[index][];

            int count = 0;
            for (int i = 0; i < index; i++)
            {
                for (int j = 0; j < jndex; j++)
                {
                    temparray[i][j] = temp[count];
                    count++;
                }
            }
            return temparray;
        }

        public static long factorial_Recursion(long number)
        {
            if (number <= (long)1)
                return 1;
            else
            {
                long a = number * factorial_Recursion(number - (long)1);
                return a;
            }
        }

        public static long Combination(long n, long m)
        {
            long total = 1;
            for (long i = n - m + 1; i <= n; i++)
            {
                total *= i;
            }
            for (long i = 1; i <= m; i++)
            {
                total /= i;
            }
            return total;
        }
  

       

        public static bool Empty<T>(this Stack<T> stack)
        {
            if (stack.Count == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

      
    }

    public static class MySort
    {

        static int a, b;

        public static int[] BubbleSort(int[] a)
        {
            for (int i = 0; i < a.Length; i++)
            {
                for (int j = 0; j < a.Length - 1; j++)
                {
                    if (a[j] > a[j + 1])
                    {
                        a.Swap(j, j + 1);
                    }
                }
            }
            return a;
        }



        public static void MergeSort(this int[] arr, int start, int end)
        {
            if (start == end) return;
            int mid = (start + end) / 2;
            arr.MergeSort(start, mid); //left inversions
            arr.MergeSort(mid + 1, end);//right inversions
            arr.Merge(start, end); // split inversions.
        }

        static void Merge(this int[] arr, int start, int end)
        {
            int mid = (start + end) / 2;
            int[] newArr = new int[end - start + 1];
            int curr = 0;
            int i = start;
            int j = mid + 1;
            while (i <= mid && j <= end)
            {
                if (arr[i] > arr[j])
                {
                    newArr[curr++] = arr[j++];
                }
                else
                    newArr[curr++] = arr[i++];
            }
            // Leftover elements here.
            while (i <= mid)
            {
                newArr[curr++] = arr[i++];
            }

            while (j <= end)
            {
                newArr[curr++] = arr[j++];
            }
            Array.Copy(newArr, 0, arr, start, end - start + 1); // Usual stuff from merge sort algorithm with arrays.
        }


        public static long MergeSortCount(int[] arr, int start, int end)
        {
            if (start == end)
                return 0;
            int mid = (start + end) / 2;
            long count = 0;
            count += MergeSortCount(arr, start, mid); //left inversions
            count += MergeSortCount(arr, mid + 1, end);//right inversions
            count += MergeCount(arr, start, end); // split inversions.
            return count;
        }

        static long MergeCount(int[] arr, int start, int end)
        {
            int mid = (start + end) / 2;
            int[] newArr = new int[end - start + 1];
            int curr = 0;
            int i = start;
            int j = mid + 1;
            long count = 0;
            while (i <= mid && j <= end)
            {
                if (arr[i] > arr[j])
                {
                    newArr[curr++] = arr[j++];
                    count += mid - i + 1; // Tricky part.
                }
                else
                    newArr[curr++] = arr[i++];
            }
            // Leftover elements here.
            while (i <= mid)
            {
                newArr[curr++] = arr[i++];
            }

            while (j <= end)
            {
                newArr[curr++] = arr[j++];
            }

            Array.Copy(newArr, 0, arr, start, end - start + 1); // Usual stuff from merge sort algorithm with arrays.
            return count;
        }


        static int[] swap(int[] arr, int i, int j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            return arr;
        }

        static int Partition(int[] arr, int l, int r)
        {
            int lst = arr[r], i = l, j = l;
            while (j < r)
            {
                if (arr[j] < lst)
                {
                    arr = swap(arr, i, j);
                    i++;
                }
                j++;
            }
            arr = swap(arr, i, r);
            return i;
        }

        static int randomPartition(int[] arr, int l, int r)
        {
            int n = r - l + 1;
            int pivot = (int)(new Random().Next() % n);
            arr = swap(arr, l + pivot, r);
            return Partition(arr, l, r);
        }

        static int MedianUtil(int[] arr, int l, int r, int k)
        {

            // if l < r 
            if (l <= r)
            {

                // Find the partition index 
                int partitionIndex = randomPartition(arr, l, r);

                // If partion index = k, then 
                // we found the median of odd 
                // number element in []arr 
                if (partitionIndex == k)
                {
                    b = arr[partitionIndex];
                    if (a != -1)
                        return int.MinValue;
                }

                // If index = k - 1, then we get 
                // a & b as middle element of 
                // []arr 
                else if (partitionIndex == k - 1)
                {
                    a = arr[partitionIndex];
                    if (b != -1)
                        return int.MinValue;
                }

                // If partitionIndex >= k then 
                // find the index in first half 
                // of the []arr 
                if (partitionIndex >= k)
                    return MedianUtil(arr, l, partitionIndex - 1, k);

                // If partitionIndex <= k then 
                // find the index in second half 
                // of the []arr 
                else
                    return MedianUtil(arr, partitionIndex + 1, r, k);
            }

            return int.MinValue;
        }

        public static float FindMedian(int[] arr, int n)
        {
            float ans;
            a = -1;
            b = -1;

            // If n is odd 
            if (n % 2 == 1)
            {
                MedianUtil(arr, 0, n - 1, n / 2);
                ans = b;
            }

            // If n is even 
            else
            {
                MedianUtil(arr, 0, n - 1, n / 2);
                ans = (float)(a + b) / 2;
            }

            return ans;
        }

        public static float FindMedian(int[] arr)
        {
            float ans;
            a = -1;
            b = -1;
            int length = arr.Length;

            // If n is odd 
            if (length % 2 == 1)
            {
                MedianUtil(arr, 0, length - 1, length / 2);
                ans = b;
            }

            // If n is even 
            else
            {
                MedianUtil(arr, 0, length - 1, length / 2);
                ans = (float)(a + b) / 2;
            }

            return ans;
        }
    }

    public static class QuickMedian
    {

        public static double FindMedian(int[] cntArr, int d)
        {
            int cnt = 0;
            double rslt = 0;

            if (d % 2 != 0)
            {
                for (int i = 0; i < cntArr.Length; i++)
                {
                    cnt += cntArr[i];

                    if (cnt > d / 2)
                    {
                        rslt = i;
                        break;
                    }
                }
            }
            else
            {
                int first = 0;
                int second = 0;

                for (int i = 0; i < cntArr.Length; i++)
                {
                    cnt += cntArr[i];
                    if (first == 0 && cnt >= d / 2)
                    {
                        first = i;
                    }
                    if (second == 0 && cnt >= d / 2 + 1)
                    {
                        second = i;
                        break;
                    }
                }
                rslt = (first + second) / 2.0;
            }
            return rslt;
        }

    }

    namespace Vector2
    {

        public struct MyVec2Int
        {
            public int x;
            public int y;

            public MyVec2Int(int x, int y)
            {
                this.x = x;
                this.y = y;
            }

            public static MyVec2Int operator +(MyVec2Int first, MyVec2Int second)
            {
                return new MyVec2Int(first.x + second.x, first.y + second.y);
            }

            public static MyVec2Int operator -(MyVec2Int first, MyVec2Int second)
            {
                return new MyVec2Int(first.x - second.x, first.y - second.y);
            }

            public static bool operator ==(MyVec2Int first, MyVec2Int second)
            {
                return first.x == second.x && first.y == second.y ? true : false;
            }

            public static bool operator !=(MyVec2Int first, MyVec2Int second)
            {
                return first.x != second.x || first.y != second.y ? false : true;
            }

            public bool Equals(MyVec2Int other)
            {
                return Equals(other, this);
            }

            public override bool Equals(object obj)
            {
                if (obj == null || GetType() != obj.GetType())
                {
                    return false;
                }

                var objectToCompareWith = (MyVec2Int)obj;

                return objectToCompareWith.x == x && objectToCompareWith.y == y;

            }

            public override int GetHashCode()
            {
                var calculation = x + y;
                return calculation.GetHashCode();
            }
        }
    }


    public static class MyMath {
        public static int DivisorSum(int n)
        {
            int sum = 0;
            int sqrt = (int)Math.Sqrt(n);
            for (int i = 1; i <= sqrt; i++)
                if (n % i == 0)
                    sum += i + n / i;
            if (sqrt * sqrt == n)
                sum -= sqrt;
            return sum;
        }

        public static int[] DivisorArr(int n)
        {
            List<int> divisor = new List<int>();
            int sqrt = (int)Math.Sqrt(n);
            for (int i = 1; i <= sqrt; i++)
                if (n % i == 0) {
                    divisor.Add(i);
                    divisor.Add(n / i);
                }
            return divisor.ToArray();
        }

        public static int DivisorCount(int n)
        {
            int count = 0;
            int sqrt = (int)Math.Sqrt(n);
            for (int i = 1; i <= sqrt; i++)
                if (n % i == 0)
                    count += 2;
            if (sqrt * sqrt == n)
                count--;
            return count;
        }
    }

}


