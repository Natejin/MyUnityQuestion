using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using NateJin;
namespace ConsoleApp3.Interview_Preparation_Kit
{
    public static class Search
    {

        public static void SearchMethod() {

            Console.WriteLine("1: whatFlavors\n 2: ");
            int fuctionNum = Convert.ToInt32(Console.ReadLine());
            string testMethod = "";
            switch (fuctionNum)
            {
                case 1:
                    testMethod = "whatFlavors";
                    break;
                default:
                    break;
            }

            string startupPath = System.IO.Directory.GetCurrentDirectory();
            string projectDirectory = Directory.GetParent(startupPath).Parent.Parent.FullName;
            string textDirectory = "";

            textDirectory = projectDirectory += @"\TextFile\Search";
            Console.WriteLine(textDirectory);
            var fCount = Directory.GetFiles(textDirectory, "*", SearchOption.TopDirectoryOnly);
            for (int i = 0; i < fCount.Length; i++)
            {
                if (fCount[i].Contains(testMethod))
                {
                    Console.WriteLine();
                    Console.WriteLine("======" + fCount[i] + " ======");

                    string textname = fCount[i];

                    if (File.Exists(textname))
                    {
                        StreamReader file = new StreamReader(textname);
                       
                        int t = Convert.ToInt32(file.ReadLine());

                        for (int tItr = 0; tItr < t; tItr++)
                        {
                            int money = Convert.ToInt32(file.ReadLine());

                            int n = Convert.ToInt32(file.ReadLine());
                            string a = file.ReadLine();


                            int[] cost = Array.ConvertAll(file.ReadLine().Split(' '), costTemp => Convert.ToInt32(costTemp))
                            ;
                            whatFlavors(cost, money);
                        }
                    }
                    Console.WriteLine();
                }
            }
        }

        static void whatFlavors(int[] cost, int money)
        {
            int diff = 2147483647;
            int flavor1 = -1;
            int flavor2 = -1;
            for (int i = 0; i < cost.Length - 1; i++)
            {
                for (int j = i + 1; j < cost.Length; j++)
                {
                    int remainMoney = money - cost[i] - cost[j];
                    if (remainMoney > 0 && diff > remainMoney)
                    {
                        flavor1 = i;
                        flavor2 = j;
                        diff = remainMoney;
                    }
                    else if (remainMoney == 0)
                    {
                        flavor1 = i;
                        flavor2 = j;
                        break;
                    }
                }
            }
            Console.WriteLine("{0} {1}", flavor1 + 1, flavor2 + 1);
        }

        static void whatFlavors1(int[] cost, int money)
        {
            int flavor1 = -1;
            int flavor2 = -1;
            int dif = 2147483647;
            int previuoudDif = 0;
            Dictionary<int, int> tempDic = new Dictionary<int, int>();

            for (int i = 0; i < cost.Length; i++)
            {
                if (tempDic.ContainsKey(money - cost[i]))
                {
                    flavor1 = tempDic[money - cost[i]];
                    flavor2 = i;
                    break;
                }
                else
                {
                    tempDic.Add(cost[i], i);
                    if (dif > previuoudDif - cost[i])
                    {
                        previuoudDif = money - cost[i];
                        dif = previuoudDif - cost[i];
                        flavor1 = flavor2;
                        flavor2 = i;
                    } 
                }
            }
            Console.WriteLine("{0} {1}", flavor1 + 1, flavor2 + 1);
        }

        static void whatFlavors2(int[] cost, int money)
        {
            Array.Sort(cost);
            int lhs = 0, rhs = cost.Length;
            while (lhs < rhs) {
                int sum = cost[lhs] + cost[rhs];
                if (sum == money) {
                    Console.WriteLine("{0} {1}", lhs + 1, rhs + 1);
                }
                else if (sum < money) lhs++;
                else rhs--;
            }
            Console.WriteLine("{0} {1}", lhs + 1, rhs + 1);
        }


        static void inorder(Node cur, List<int> list)
        {
            if (cur == null) return;

            inorder(cur.left, list);
            list.Add(cur.d);
            inorder(cur.right, list);
        }

        static void swap(Node cur, int depth, int k)
        {
            if (cur == null) return;

            if (depth >= k && depth % k == 0)
            {
                Node t = cur.left;
                cur.left = cur.right;
                cur.right = t;
            }

            swap(cur.left, depth + 1, k);
            swap(cur.right, depth + 1, k);
        }

        static int[][] swapNodes(int[][] indexes, int[] queries)
        {
            int[][] result = new int[queries.Length][];
            //Node root = new Node(1, null, null);
            //Node cur = root;

            //Queue<Node> nodes = new Queue<Node>();
            //nodes.Peek(cur);

            //int N = 0;
            //while (N < indexes.Length)
            //{
            //    cur = nodes.Peek();

            //    cur.left = (indexes[N][0] == -1) ? null : new Node(indexes[N][0], null, null);
            //    cur.right = (indexes[N][1] == -1) ? null : new Node(indexes[N][1], null, null);

            //    if (cur.left != null && cur.left.d != -1) nodes.offer(cur.left);
            //    if (cur.right != null && cur.right.d != -1) nodes.offer(cur.right);
            //    N++;
            //}

            //for (int i = 0; i < queries.Length; i++)
            //{
            //    swap(root, 1, queries[i]);
            //    List<int> list = new List<int>();
            //    inorder(root, list);
            //    result[i] = list.stream().mapToInt(v->v).toArray();
            //}

            return result;
        }

        static int pairs(int k, int[] arr)
        {
            Dictionary<int, int> target = new Dictionary<int, int>();
            int count = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                target.Add(arr[i], i);
            }

            foreach (var item in target)
            {
                if (target.ContainsKey(item.Key + k))
                {
                    count++;
                }
                
            }
            return count;
        }

        static int pairs1(int k, int[] arr)
        {
            Array.Sort(arr);

            int count = 0;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                if (arr.Contains(arr[i] + k))
                {
                    count++;
                }
            }
            return count;
        }

        static long triplets(int[] a, int[] b, int[] c)
        {
            Array.Sort(a);
            Array.Sort(b);
            Array.Sort(c);
            int aLength = a.Length - 1;
            int bLength = b.Length - 1;
            int cLength = c.Length - 1;

            Dictionary<int, long> aDic = new Dictionary<int, long>();
            Dictionary<int, long> bDic = new Dictionary<int, long>();
            Dictionary<int, long> cDic = new Dictionary<int, long>();

            bool aDone = true;
            bool bDone = true;
            bool cDone = true;
            int getIndexAt = 0;

            int countA = 0;
            int countB = 0;
            int countC = 0;

            while (aDone || bDone || cDone)
            {
                if (aDone && !aDic.ContainsKey(a[getIndexAt]))
                {
                    countA++;
                    aDic.Add(a[getIndexAt], countA);
                }

                if (bDone && !bDic.ContainsKey(b[getIndexAt]))
                {
                    countB++;
                    bDic.Add(b[getIndexAt], countB);
                }

                if (cDone && !cDic.ContainsKey(c[getIndexAt]))
                {
                    countC++;
                    cDic.Add(c[getIndexAt], countC);
                }

                getIndexAt++;
                if (aLength == getIndexAt) aDone = false;
                if (bLength == getIndexAt) bDone = false;
                if (cLength == getIndexAt) cDone = false;
            }

            int[] aKeysArray = aDic.Keys.ToArray();
            int[] bKeysArray = bDic.Keys.ToArray();
            int[] cKeysArray = cDic.Keys.ToArray();

            int aCount = 0;
            int bCount = 0;
            int cCount = 0;
            int bkeyLength = bKeysArray.Length - 1;
            long sum = 0;

            Console.WriteLine("{0} {1} {2}", aKeysArray.Length, bKeysArray.Length, cKeysArray.Length);
            while (bkeyLength  == bCount)
            {
                Console.WriteLine("{0} {1} {2}", aCount, bCount, cCount);
                if (bKeysArray[bCount] < aKeysArray[aCount] || bKeysArray[bCount] < cKeysArray[cCount])
                {
                    bCount++;
                }
                else {
                    if (aKeysArray.Length > aCount + 1 && bKeysArray[bCount] > aKeysArray[aCount + 1] )
                    {
                        aCount++;
                        continue;
                    }

                    if (cKeysArray.Length > cCount + 1 && bKeysArray[bCount] > cKeysArray[cCount + 1] )
                    {
                        cCount++;
                        continue;
                    }

                    sum += aDic[aKeysArray[aCount]] * cDic[cKeysArray[ cCount]];
                    aCount = 0;
                    cCount = 0;
                    Console.WriteLine("{0}", sum);
                    bCount++;
                }
            }
            return sum;

        }

        static long triplets1(int[] a, int[] b, int[] c)
        {
            a = a.Distinct().OrderBy(f => f).ToArray();
            b = b.Distinct().OrderBy(f => f).ToArray();
            c = c.Distinct().OrderBy(f => f).ToArray();

            long i = 0;
            long j = 0;
            long sum = 0;

            foreach (var val in b)
            {
                while (i < a.Length && a[i] <= val) i++;
                while (j < c.Length && c[j] <= val) j++;

                sum += i * j;
            }

            return sum;
        }

        static long triplets2(int[] a, int[] b, int[] c)
        {
            long count = 0;
            a = a.Distinct().OrderBy(x => x).ToArray();
            b = b.Distinct().OrderBy(x => x).ToArray();
            c = c.Distinct().OrderBy(x => x).ToArray();


            for (int i = 0; i < b.Length; i++)
            {
                int v = b[i];
                long aC = Array.BinarySearch(a, v);
                if (aC < 0) aC = ~aC;
                else aC++;

                long cC = Array.BinarySearch(c, v);
                if (cC < 0) cC = ~cC;
                else cC++;

                count += aC * cC;
            }
            return count;
        }

        /* method 1 */
        static long binarySearchIter(long[] machines, long goal, long minDay, long maxDay)
        {
            long mid = 0;
            long prd = 0;

            while (minDay < maxDay)
            {
                prd = 0;
                mid = (minDay + maxDay) / 2;

                for (int i = 0; i < machines.Length; i++)
                {
                    prd += mid / machines[i];
                }

                if (prd >= goal)
                {
                    maxDay = mid;
                }
                else if (prd < goal)
                {
                    minDay = mid + 1;
                }
            }
            return minDay;
        }

        /* method 2 */
        static long binarySearchRecursive(long[] machines, long goal, long minDay, long maxDay)
        {
            if (minDay == maxDay) return minDay;

            long mid = (minDay + maxDay) / 2;
            long prd = 0;

            for (int i = 0; i < machines.Length; i++)
            {
                prd += mid / machines[i];
            }

            if (prd >= goal)
            {
                return binarySearchRecursive(machines, goal, minDay, mid);
            }
            else if (prd < goal)
            {
                return binarySearchRecursive(machines, goal, mid + 1, maxDay);
            }
            return -1;
        }

        public static long minTime(long[] machines, long goal)
        {
            Array.Sort(machines);
            return binarySearchIter(machines, goal, 1, machines[machines.Length - 1] * goal);             /* iter */
            //return binarySearchRecursive(machines, goal, 1, machines[machines.length-1] * goal);      /* recursive */
        }

        public static long minTime1(long[] machines, long goal)
        {
            Array.Sort(machines);
            //return binarySearchIter(machines, goal, 1, machines[machines.Length - 1] * goal);             /* iter */
            return binarySearchRecursive(machines, goal, 1, machines[machines.Length - 1] * goal);      /* recursive */
        }

        public static long minTime2(long[] machines, long goal)
        {
            Array.Sort(machines);
            long minDay = 1;
            long maxDay = machines[machines.Length - 1] * goal;
            long prd = 0;

            while (minDay < maxDay)
            {
                long midDay = (minDay + maxDay) / 2;

                for (int i = 0; i < machines.Length; i++)
                {
                    prd += midDay / machines[i];
                }

                if (prd > goal)
                {
                    maxDay = midDay;
                }
                else
                {
                    minDay = midDay + 1;
                }
            }
            return minDay;
            
        }
        static void TreeMaps()
        {
            SortedDictionary<string, int> map = new SortedDictionary<string, int>();
            string s = "test";
            map[s] = 1;
            int i = map[s];
            i = map.Count;
            bool b = map.Count == 0;
            map.Remove(s);
        }

        static long maximumSum(long[] a, long m)
        {
            long sum = 0;
            long remain = 0;
            for (int i = 0; i < a.Length; i++)
            {
                sum = 0;
                sum += a[i];
                long tempRemain = sum % m;
                remain = Math.Max(tempRemain, remain);
                if (remain == m - 1) return remain;
                remain = Math.Max(DCF_maximumSum(a, i, i + 1, sum, m, remain), remain);
            }
            return remain;
        }

        static long DCF_maximumSum(long[] a, int start, int end, long sum, long m, long remain)
        {
            if (a.Length == end) return remain;
            sum += a[end];
            long tempRemain = sum % m;
            remain = Math.Max(tempRemain, remain);
            if (remain == m - 1) return remain;
            return DCF_maximumSum(a, start, end + 1, sum, m, remain);
        }

        static long maximumSum1(long[] a, long m)
        {
            long sum = 0;
            long remain = 0;
            long[] DPArr = new long[a.Length];
            for (int i = 0; i < a.Length; i++)
            {
                if (DPArr[i] == 0) DPArr[i] = a[i] % m;
                if (DPArr[i] == m - 1) return DPArr[i];
                long tempRemain = remain + DPArr[i];
                if (tempRemain > m) tempRemain -= m;
                remain = Math.Max(tempRemain, remain);
                remain = Math.Max(remain,  DCF_maximumSum1(a, i + 1, sum, m, remain, ref DPArr));
                if (remain == m - 1) return remain;
            }
            return remain;
        }

        static long DCF_maximumSum1(long[] a,  int end, long sum, long m, long remain, ref long[] DPArr)
        {
            if (a.Length == end) return remain;
            if (DPArr[end] == 0) DPArr[end] = a[end] % m;
            long tempRemain = remain + DPArr[end];
            if (tempRemain > m) tempRemain -= m;
            remain = Math.Max(tempRemain, remain);
            if (remain == m - 1) return remain;
            return DCF_maximumSum1(a, end + 1, sum, m, remain, ref DPArr);
        }

        static long maximumSum2(long[] a, long m)
        {
           
            long[] DPArr = new long[a.Length];
            long curr = 0;
            for (int i = 0; i < a.Length; i++)
            {
                curr = (a[i] % m + curr) % m;
                if (curr == m - 1) return curr;
                DPArr[i] = curr;
            }

            long ret = 0;
            for (int i = 0; i < a.Length; i++)
            {
                for (int j = i - 1; j >= 0; j--)
                {
                    ret = Math.Max(ret, (DPArr[i] - DPArr[j] + m) % m);
                    if (ret == m - 1) return ret;
                }
                ret = Math.Max(ret, DPArr[i]); // Don't forget sum from beginning.

            }
            return ret;
        }

        static long maximumSum3(long[] a, long m)
        {

            long max = 0;
            long modSum = 0;
            SortedSet<long> modSums = new SortedSet<long>();

            foreach (long v in a)
            {
                modSum = (modSum + v) % m;
                long closesetLargerSum = modSums.ElementAfter(modSum);

                if (closesetLargerSum > 0)
                {
                    max = Math.Max(max, modSum - closesetLargerSum + m);
                }
                max = Math.Max(max, modSum);
                modSums.Add(modSum);
            }
            return max;
        }

        static int DCF_connectedCell(int[][] matrix, ref int[,] scanned, int i, int j, int count)
        {
            if (i == matrix.Length || i < 0) return count;
            if (j == matrix[i].Length || j < 0) return count;
            if (scanned[i, j] == 1) return count;
            if (matrix[i][j] == 0) return count;
            count += matrix[i][j];
            scanned[i, j] = 1;
            Console.WriteLine("i: {0} j: {1} count: {2}", i, j, count);
            count = DCF_connectedCell(matrix, ref scanned, i + 1, j, count);
            count = DCF_connectedCell(matrix, ref scanned, i, j + 1, count);
            count = DCF_connectedCell(matrix, ref scanned, i - 1, j, count);
            count = DCF_connectedCell(matrix, ref scanned, i, j - 1, count);
            count = DCF_connectedCell(matrix, ref scanned, i + 1, j + 1, count);
            count = DCF_connectedCell(matrix, ref scanned, i - 1, j + 1, count);
            count = DCF_connectedCell(matrix, ref scanned, i + 1, j - 1, count);
            count = DCF_connectedCell(matrix, ref scanned, i - 1, j - 1, count);
            return count;
        }

        static int connectedCell(int[][] matrix)
        {
            int[,] scanned = new int[matrix.Length, matrix[0].Length];

            int count = 0;
            for (int i = 0; i < matrix.Length; i++)
            {

                for (int j = 0; j < matrix[i].Length; j++)
                {
                    if (scanned[i, j] == 1) continue;
                    count = Math.Max(count, DCF_connectedCell(matrix, ref scanned, i, j, 0));
                }
            }
            return count;
        }
    }

    public class Node
    {
        public int d;
        public Node right;
        public Node left;

        public Node(int root, Node left, Node right)
        {
            this.left = left;
            this.right = right;
            this.d = root;
        }
    }

}

