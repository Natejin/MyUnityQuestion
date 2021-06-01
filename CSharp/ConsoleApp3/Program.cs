using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using ConsoleApp3.Interview_Preparation_Kit;
using NateJin;

namespace ConsoleApp3
{
    class Program
    {
    
        static void Main(string[] args)
        {
            while (true)
            {

                int[] array = new int[1000000];
                Dictionary<int, int> dic = new Dictionary<int, int>();

                for (int j = 0; j < 1000000; j++)
                {
                    dic.Add(j, 0);
                }

                string type = Console.ReadLine();
                int runCount = Convert.ToInt32( Console.ReadLine());
                Stopwatch sw = new Stopwatch();
                sw.Start();
                switch (type)
                {
                    case "1":

                        for (int i = 0; i < runCount; i++)
                        {
                            array.Contains(2);
                        }
       
                        break;
                    case "2":
                        for (int i = 0; i < runCount; i++)
                        {
                            dic.ContainsKey(2);
                        }
                        break;
                    default:
                        break;
                }





                sw.Stop();
                Console.WriteLine(sw.ElapsedMilliseconds);
            }


            

             
        }

        public static void test(int[] arr) {
            Array.Sort(arr);
            int total = 0;
            for (int i = 0; i < 32; i++)
            {
                total += arr[i] * 2;
            }
            for (int i = 32; i < 38; i++)
            {
                total += arr[i] * 3;
            }
            for (int i = 38; i < arr.Length; i++)
            {
                total += arr[i];
            }
            Console.WriteLine(total);

        }

        static long countInversions(int[] arr)
        {
            int count = 0;
            for (int i = 0; i < arr.Length - 1; i++)
            {
                for (int j = i + 1; j < arr.Length; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        arr.Swap(i, j);
                        count++;
                    }
                }
            }
            return count;
        }

        #region
        //문제 설명
        //주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다.숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.
        //제한사항
        //nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
        //nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.

        static int[] primeList = new int[430] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                                  31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                                  73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
                                  127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
                                  179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
                                  233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                                  283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
                                  353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
                                  419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
                                  467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
                                  547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
                                  607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
                                  661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
                                  739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
                                  811, 821, 823, 827, 829, 839, 853, 857, 859, 863,
                                  877, 881, 883, 887, 907, 911, 919, 929, 937, 941,
                                  947, 953, 967, 971, 977, 983, 991, 997, 1009, 1013,
                                  1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
                                  1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151,
                                  1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223,
                                  1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291,
                                  1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373,
                                  1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451,
                                  1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511,
                                  1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583,
                                  1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657,
                                  1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733,
                                  1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811,
                                  1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889,
                                  1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987,
                                  1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053,
                                  2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129,
                                  2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213,
                                  2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287,
                                  2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357,
                                  2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423,
                                  2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531,
                                  2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617,
                                  2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687,
                                  2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741,
                                  2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819,
                                  2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903,
                                  2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999};
        static int 세수의합이소수인지확인(int[] nums)
        {
            int Count = 0;
            //List<int> usedNumber = new List<int>();
            for (int i = 0; i < nums.Length - 2; i++)
            {
                for (int j = 0; j < nums.Length - 1; j++)
                {
                    if (j <= i)
                    {
                        continue;
                    }
                    for (int k = 0; k < nums.Length; k++)
                    {
                        if (k <= i || k <= j)
                        {
                            continue;
                        }
                        int sum = nums[i] + nums[j] + nums[k];
                        //Console.WriteLine(i + "," + j + "," + k +" = " + sum);
                        if (Array.Exists(primeList, x => x == sum))
                        {
                            //Console.WriteLine("Its Prime : " + sum);
                            //usedNumber.Add( sum);
                            Count++;
                        }
                        //if (IsPrimeNumber(sum))
                        //{
                        //    //Console.WriteLine("Its Prime : " + sum);
                        //    //usedNumber.Add( sum);
                        //    Count++;
                        //}
                    }
                }
            }
            return Count;
        }

        bool 이건소수야(int n)
        {
            int i = 0;
            int last = n / 2;
            if (n <= 1)
            {
                return false;
            }

            for (i = 2; i <= last; i++)
            {
                if ((n % i) == 0)
                {
                    return false;
                }
            }
            return true;
        }

        #endregion

        #region 스킬트리
        public int solution(string skill, string[] skill_trees)
        {

            var skills = skill.ToCharArray();
            int count = 0;
            for (int i = 0; i < skill_trees.Length; i++)
            {
                List<char> dataList = new List<char>();
                dataList.AddRange(skill_trees[i]);
                List<int> skilltree = new List<int>();
                Console.WriteLine("Start");
                for (int j = 0; j < skills.Length; j++)
                {
                    if (dataList.IndexOf(skills[j]) == -1)
                    {
                        continue;
                    }

                    if (skilltree.Count > 0)
                    {

                        if (skilltree[skilltree.Count - 1] < dataList.IndexOf(skills[j]))
                        {
                            Console.WriteLine(skilltree[skilltree.Count - 1] + "||" + dataList.IndexOf(skills[j]));
                            skilltree.Add(dataList.IndexOf(skills[j]));
                        }
                        else
                        {
                            break;
                        }

                    }
                    else
                    {

                        Console.WriteLine(dataList.IndexOf(skills[j]));
                        skilltree.Add(dataList.IndexOf(skills[j]));
                    }
                    if (j == skills.Length - 1)
                    {
                        count++;
                    }
                }
            }
            return count;

        }
        #endregion

        static void PlusMinus()
        {
            int n = Convert.ToInt32(Console.ReadLine());

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
            ;
            plusMinus(arr);
        }

        static void plusMinus(int[] arr)
        {
            int[] answer = new int[3];

            int size = arr.Length;

            for (int i = 0; i < size; i++)
            {
                if (arr[i] > 0)
                    answer[0]++;
                else if (arr[i] < 0)
                    answer[1]++;
                else
                    answer[2]++;

            }

            foreach (var item in answer)
            {
                Console.WriteLine(((float)item / size).ToString("N6"));
            }
        }



        static void staircase(int n)
        {

            for (int i = 0; i < n - 1; i++)
            {
                Console.WriteLine(new String(' ', n - i) + new String('#', i));
            }

            staircase_DCF(n, n);
            Console.WriteLine(new String('#', n));

        }
        static void staircase_DCF(int n, int max)
        {
            if (n == 1)
            {
                return;
            }
            else
            {
                staircase_DCF(--n, max);
                Console.WriteLine(new String(' ', max - n) + new String('#', n));
            }

        }
        static void miniMaxSum()
        {
            miniMaxSum(new int[] { 942381765, 627450398, 954173620, 583762094, 236817490 });
        }

        static void miniMaxSum(int[] arr)
        {
            arr = arr.OrderBy(x => x).ToArray();
            long middle = (long)arr[1] + (long)arr[2] + (long)arr[3];
            Console.WriteLine((arr[0] + middle) + " " + (middle + arr[4]));
        }

        static int birthdayCakeCandles(int[] ar)
        {

            Dictionary<int, int> candleDic = new Dictionary<int, int>();
            for (int i = 0; i < ar.Length; i++)
            {
                if (candleDic.ContainsKey(ar[i]))
                {
                    candleDic[ar[i]]++;
                }
                else
                {
                    candleDic.Add(ar[i], 1);
                }

            }
            return candleDic[candleDic.Keys.OrderByDescending(x => x).ToList()[0]];

        }

        static int birthdayCakeCandles1(int[] ar)
        {
            var heights = ar;
            var max = heights.Max();
            var count = heights.Count(it => it == max);
            return count;

        }

        static int birthdayCakeCandles2(int[] ar)
        {
            int max = 0;
            int count = 0;

            for (int i = 0; i < ar.Length; i++)
            {
                if (ar[i] > max)
                {
                    count = 1;
                }
                else if (ar[i] == max)
                {
                    count++;
                }


            }
            return count;

        }

        static string timeConversion(string s)
        {
            //DateTime time = DateTime.ParseExact(s, "hh:mm:sstt", CultureInfo.InvariantCulture);
            DateTime time = Convert.ToDateTime(s);
            return time.ToString("HH:mm:ss");

        }

        static int introTutorial(int V, int[] arr)
        {

            return Array.IndexOf(arr, V);
        }

        static void insertionSort1(int n, int[] arr)
        {
            int hold = 0;
            bool trigger = false;
            for (int i = arr.Length - 1; i >= 0; i--)
            {
                string output = "";
                if (trigger)
                {
                    if (i == 0)
                    {
                        arr[i] = hold;
                    }
                    else
                    {
                        if (hold < arr[i - 1])
                        {

                            arr[i] = arr[i - 1];

                        }
                        else
                        {
                            arr[i] = hold;
                            for (int j = 0; j < arr.Length; j++)
                            {
                                output += arr[j];
                                if (arr.Length - 1 > j)
                                {
                                    output += " ";
                                }
                            }
                            Console.WriteLine(output);

                            break;
                        }
                    }

                }
                else
                {
                    if (arr[i] < arr[i - 1])
                    {
                        trigger = true;
                        hold = arr[i];
                        arr[i] = arr[i - 1];
                    }
                }
                for (int j = 0; j < arr.Length; j++)
                {
                    output += arr[j];
                    if (arr.Length - 1 > j)
                    {
                        output += " ";
                    }
                }
                Console.WriteLine(output);
            }

        }


        public static List<int> gradingStudents(List<int> grades)
        {

            for (int i = 0; i < grades.Count; i++)
            {
                if (grades[i] >= 38)
                {
                    if (grades[i] % 5 >= 3)
                    {
                        grades[i] += grades[i] % 5;
                    }
                }
            }
            return grades;
        }

        static int sockMerchant(int n, int[] ar)
        {
            Dictionary<int, int> sockDic = new Dictionary<int, int>();
            for (int i = 0; i < ar.Length; i++)
            {
                if (sockDic.ContainsKey(ar[i]))
                {
                    sockDic[ar[i]]++;
                }
                else
                {
                    sockDic.Add(ar[i], 1);
                }
            }

            int totalPair = 0;
            foreach (var item in sockDic)
            {
                totalPair += item.Value / 2;
            }
            return totalPair;
        }

        static int sockMerchant1(int n, int[] ar)
        {
            Array.Sort(ar);

            int previousColor = -1;
            int count = 1;
            int totalCount = 0;
            for (int i = 0; i < ar.Length; i++)
            {
                if (previousColor != ar[i] || i == ar.Length - 1)
                {
                    if (i == ar.Length - 1)
                    {
                        count++;
                    }
                    Console.WriteLine(count);
                    totalCount += count / 2;
                    previousColor = ar[i];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            return totalCount;
        }
        static int countingValleys(int n, string s)
        {
            int count = 0;
            int seaLvl = 0;
            if (s[0] == 'U') seaLvl++;
            if (s[0] == 'L') seaLvl++;
            for (int i = 1; i < s.Length; i++)
            {
                if (s[i] == 'U') {
                    seaLvl++;
                    if (seaLvl == 0)
                    {
                        count++;
                    }
                } 
                if (s[i] == 'L') seaLvl++;
                Console.WriteLine(seaLvl + "||" + count);
        
            }
            return count;
        }

        static int jumpingOnClouds(int[] c)
        {
            int count = 0;
            for (int i = 0; i < c.Length - 1; i++)
            {
                if (c[i] == 0) i++;
                count++;
            }
            return count;
        }

        static void repeatedString() {
            repeatedString("ojowrdcpavatfacuunxycyrmpbkvaxyrsgquwehhurnicgicmrpmgegftjszgvsgqavcrvdtsxlkxjpqtlnkjuyraknwxmnthfpt", 685118368975);
        }

        static long repeatedString(string s, long n)
        {
            int size = s.Length;
            int count = s.Count(f => f == 'a');
            long totalCount = n / size * count;
            long reminder = n % size;
            //Console.WriteLine(s.Substring(0, (int)reminder));
            //Console.WriteLine("Length : " + size + " Count : " + count + "totalCount : " + totalCount + " reminder : " +  reminder + " reminderCount : " + s.Substring(0, (int)reminder).Count(f => f == 'a'));

            if (reminder > 0)
            {
                //Console.WriteLine(totalCount + s.Substring((int)reminder).Count(f => f == 'a'));
                return totalCount + s.Substring(0, (int)reminder).Count(f => f == 'a');
            }
            else {
                Console.WriteLine(totalCount);
                return totalCount;
            }
            
        }

        static int hourglassSum(int[][] arr)
        {
            int highestSum = -2147483648;
            for (int i = 0; i < arr.Length - 2; i++)
            {

                for (int j = 0; j < arr[i].Length -2; j++)
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

        static int[] rotLeft(int[] a, int d)
        {
            int[] temp = new int[a.Length];

            Array.Copy(a, d, temp, 0, a.Length -d);
            Array.Copy(a, 0, temp, a.Length - d, d);
            return temp;
        }

        static void minimumBribes(int[] q)
        {
            int count = 0;
            
            for (int i = 0; i < q.Length ; i++)
            {
                if (q[i] - (i + 1) > 2)
                {
                    Console.WriteLine("Too chaotic");
                    return;
                }
                for (int j = Math.Max(0, q[i] - 2); j < i; j++)
                {

                    if (q[j] > q[i]) {
                        Console.WriteLine("i: " + i + " j: " + j + " q[i]: " + q[i] + " q[j]: " + q[j]);
                        count++;
                    } 
                }
            }
            Console.WriteLine(count);
        }

       

      

  

      
        




       
        static long countTriplets(List<long> arr, long r)
        {
            Dictionary<long, long> countDic = new Dictionary<long, long>();
            for (int i = 0; i < arr.Count; i++)
            {
                if (arr[i] % r != 0 && arr[i] != 1)
                {
                    continue;
                }
                if (countDic.ContainsKey(arr[i]))
                {
                    countDic[arr[i]]++;
                }
                else {
                    countDic.Add(arr[i], 1);
                }
            }
            var keyArr = countDic.Keys.OrderBy(x => x).ToArray();
            if (keyArr.Length <= 3 && r == 1)
            {
                return Support.Combination(arr.Count, 3);
            }
            long sum = 0;
            for (long i = 0; i < keyArr.Length -2; i++)
            {
                if (countDic.ContainsKey(keyArr[i] * r) && countDic.ContainsKey(keyArr[i] * r * r))
                {
                    sum += countDic[keyArr[i]] * countDic[keyArr[i] * r] * countDic[keyArr[i] * r * r];
                }
            }
            return sum;
        }
        static long countTriplets1(List<long> arr, long r)
        {

            Dictionary<long, long> leftMap = new Dictionary<long, long>();
            Dictionary<long, long> rightMap = new Dictionary<long, long>();


            foreach (var item in arr)
            {
                rightMap[item] = rightMap.GetOrDefault(item, 0) + 1;
            }

            long count = 0;

            for (int i = 0; i < arr.Count; i++)
            {
                long midTerm = arr[i];
                long c1 = 0, c3 = 0;

                rightMap[midTerm] = rightMap.GetOrDefault(midTerm, 0) - 1;
                if (midTerm % r == 0 && leftMap.ContainsKey(midTerm / r))
                {
                    c1 = leftMap[midTerm / r];
                }

                if (rightMap.ContainsKey(midTerm * r))
                    c3 = rightMap[midTerm * r];

                count += c1 * c3;

                leftMap[midTerm] = leftMap.GetOrDefault(midTerm, 0) + 1;

            }
            return count;
        }

        static List<int> freqQuery(List<List<int>> queries)
        {
            Dictionary<int, int> freqToVal = new Dictionary<int, int>();
            Dictionary<int, int> valueDic = new Dictionary<int, int>();

            List<int> result = new List<int>();
            int queriesCount = queries.Count;
            for (int i = 0; i < queriesCount; i++)
            {
                if (queries[i][0] == 1)
                {
                    if (freqToVal.ContainsKey(queries[i][1]))
                    {
                        valueDic.SubOrRemove(freqToVal[queries[i][1]]);
                        freqToVal[queries[i][1]]++;
                        valueDic.PlusOrAdd(freqToVal[queries[i][1]]);
                    }
                    else {
                        freqToVal.Add(queries[i][1], 1);
                        valueDic.PlusOrAdd(freqToVal[queries[i][1]]);
                    }
                }
                else if (queries[i][0] == 2)
                {
                    if (freqToVal.ContainsKey(queries[i][1]))
                    {
                        if (freqToVal[queries[i][1]] > 1)
                        {
                            valueDic.SubOrRemove(freqToVal[queries[i][1]]);
                            freqToVal[queries[i][1]]--;
                            valueDic.PlusOrAdd(freqToVal[queries[i][1]]);
                        }
                        else {
                            valueDic.SubOrRemove(freqToVal[queries[i][1]]);
                            freqToVal.Remove(queries[i][1]);
                        }
                    }
                }
                else {
                    if (valueDic.ContainsKey(queries[i][1]))
                    {
                        result.Add(1);
                    }
                    else {
                        result.Add(0);
                    }
                }
            }
            return result;
        }

    
        static long countTriplets2(List<long> arr, long r)
        {
            Dictionary<long, long> leftDic = new Dictionary<long, long>();
            Dictionary<long, long> rightDic = new Dictionary<long, long>();
            long count = 0;

            foreach (var item in arr)
            {
                rightDic.PlusOrAdd(item);
            }

            for (int i = 0; i < arr.Count; i++)
            {
                long c1 = 0, c3 = 0;
                long mid = arr[i];
                rightDic.SubOrRemove(mid);
                if (mid%r == 0 && leftDic.ContainsKey(mid/r))
                {
                    c1 = leftDic[mid / r];
                }

                if (rightDic.ContainsKey(mid * r))
                {
                    c3 = rightDic[mid * r];
                }

                count += c1 * c3;

                leftDic.PlusOrAdd(mid);
            }
            return count;
        }
    }
}

