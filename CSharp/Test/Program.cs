using Microsoft.VisualBasic.CompilerServices;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Diagnostics.CodeAnalysis;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Runtime.InteropServices.ComTypes;
using System.Text.RegularExpressions;

namespace Test
{
   static class Program
    {






        static void Main(String[] args)
        {


            //var a = ;

            //Console.WriteLine(야근_지수.solution(1, new int[] { 2, 1, 2 }));
            Console.WriteLine(두_개_뽑아서_더하기.solution(new int[] { 2, 1, 3, 4, 1 }));


        }
    }
}


public static class 두_개_뽑아서_더하기
{
    // 정수 배열 numbers가 주어집니다.numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.
    public static int[] solution(int[] numbers)
    {
        int[] answer = new int[] { };
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int max = numbers.Length - 1;
        for (int i = 0; i < max; i++)
        {
            for (int j = i + 1; j < numbers.Length; j++)
            {
                int sum = numbers[i] + numbers[j];
                if (!dic.ContainsKey(sum))
                {
                    dic.Add(sum, 1);
                }
            }
        }
        return dic.Keys.OrderBy(x => x).ToArray();
    }
}

public static class 기지국_설치
{
    public static int solution(int n, int[] stations, int w)
    {
        int answer = 0;
        int curStationIndex = 0;
        int curPos = 1;
        while (curPos <= n)
        {
            if (curStationIndex < stations.Length && curPos >= stations[curStationIndex] - w)
            {
                curPos = stations[curStationIndex] + w + 1;
                curStationIndex++;
            }
            else
            {
                curPos += w + w + 1;
                answer++;
            }
        }
        return answer;
    }
}


public static  class 야근_지수
{
    public static long solution(int n, int[] works)
    {
        int size = works.Length - 1;
        Array.Sort(works);
        int currentSelectedIndex = size;
        int sameNum = 1;
        while (n > 0)
        {
            int maxValue = works[currentSelectedIndex];

            for (int i = currentSelectedIndex; i > 0; i--)
            {
                if (maxValue > works[i - 1])
                {
                    currentSelectedIndex = i;
                    break;
                }
                sameNum++;
            }
            int secondValue = works[currentSelectedIndex - 1];
            int dif = maxValue - secondValue;
            int totalReduce = dif * sameNum;
            if (totalReduce == 0)
            {
                break;
            }
            if (totalReduce > n)
            {
                break;
            }
            else
            {
                for (int i = 0; i < sameNum; i++)
                {
                    works[currentSelectedIndex + i] = secondValue;
                }
                n -= totalReduce;
            }
        }

        while (n-- > 0)
        {
            int maxValue = works.Max();
            int maxIndex = works.ToList().IndexOf(maxValue);
            works[maxIndex]--;
            if (works[maxIndex] < 0)
                return 0;
        }
        long answer = 0;
        foreach (var item in works)
            answer += (long)Math.Pow(item, 2);
        return answer;
    }

}
    public static class 풍선_터트리기
{
    public static int solution(int[] a)
    {
        int answer = a.Length;
        int[] left = new int[a.Length];
        int[] right = new int[a.Length];
        left[0] = a[0];
        right[a.Length - 1] = a[a.Length - 1];
        for (int i = 1, j = a.Length - 2; i < a.Length; i++, j--)
        {
            left[i] = Math.Min(a[i], left[i - 1]);
            right[j] = Math.Min(a[j], right[j + 1]);
        }

        for (int i = 0; i < a.Length; i++)
        {
            if (a[i] > left[i] && a[i] > right[i])
            {
                answer--;
            }
        }
        return answer;
    }
}

public static class 베스트앨범
{
     class Song
    {
        public int id;
        public int playTime;

        public Song(int id, int playTime)
        {
            this.id = id;
            this.playTime = playTime;
        }
    }

    public static int[] solution(string[] genres, int[] plays)
    {
        Dictionary<string, List<Song>> dicPlay = new Dictionary<string, List<Song>>();
        for (int i = 0; i < genres.Length; i++)
        {
            if (dicPlay.ContainsKey(genres[i]))
            {
                dicPlay[genres[i]].Add(new Song(i, plays[i]));
            }
            else
            {
                dicPlay.Add(genres[i], new List<Song>() { new Song(i, plays[i]) });
            }
        }
        SortedDictionary<string, int> sortDic = new SortedDictionary<string, int>();

        for (int i = 0; i < dicPlay.Count; i++)
        {
            var item = dicPlay.Keys.ToArray();
            dicPlay[item[i]] = dicPlay[item[i]].OrderBy(x => x.playTime).ToList();
            sortDic.Add(item[i], dicPlay[item[i]][dicPlay[item[i]].Count - 1].playTime);
        }
       
        List<int> answer = new List<int>();

        foreach(var item in sortDic.OrderByDescending(key => key.Value))
{
            if (dicPlay[item.Key].Count == 1)
            {
                answer.Add(dicPlay[item.Key][0].id);
            }
            else
            {
                answer.Add(dicPlay[item.Key][dicPlay[item.Key].Count - 1].id);
                answer.Add(dicPlay[item.Key][dicPlay[item.Key].Count - 2].id);
            }
        }

       
        return answer.ToArray();
    }
}

public static class 여행경로
{
    public static string[] solution(string[,] tickets)
    {
        string[] answer = new string[] { };
        List<string[]> vs = new List<string[]>();

        for (int i = 0; i < tickets.GetLength(0); i++)
        {
            vs.Add(new string[] { tickets[i, 0], tickets[i, 1] });
        }

        List<string> airPortsList = new List<string>();
        string airports = "ICN";
        FindAirport(airports, "ICN", vs.ToArray(), ref airPortsList);

        airPortsList.Sort();
        answer = airPortsList.First().Split(',');

        return answer;
    }

    private static void FindAirport(string airports, string lastAirPort, string[][] remainTickets, ref List<string> airportsList)
    {
        foreach (string[] item in remainTickets.Where(s => s[0] == lastAirPort))
        {
            string tempAirports = string.Format("{0},{1}", airports, item[1]);
            if (remainTickets.Count() == 1)
            {
                airportsList.Add(tempAirports);
                return;
            }
            List<string[]> tempTickets = remainTickets.ToList();
            tempTickets.Remove(item);
            FindAirport(tempAirports, item[1], tempTickets.ToArray(), ref airportsList);
        }
    }
}

public static class 순위_문제
{
    public static int solution(int n, int[,] results)
    {
        int[][] scores = new int[n + 1][];

        for (int i = 1; i <= n; i++)
        {
            scores[i] = new int[n + 1];
            for (int j = 1; j <= n; j++)
            {
                scores[i][j] = i == j ? 0 : 987654321;
            }
        }

        for (int i = 0; i < results.GetLength(0); i++)
        {
            int a = results[i, 0];
            int b = results[i, 1];
            scores[a][b] = 1;
        }


        for (int a = 1; a <= n; a++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i != j && j != a && i != a)
                    {
                        scores[i][j] = Math.Min(scores[i][j], scores[i][a] + scores[a][j]);
                    }
                }
            }
        }

        bool[] flag = new bool[n + 1];
        flag = Enumerable.Repeat(true, flag.Length).ToArray();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                if (scores[i][j] == 987654321)
                {
                    if (scores[j][i] == 987654321)
                    {
                        flag[i] = false;
                        break;
                    }
                }
            }
        }

        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            if (flag[i]) cnt++;
        }

        return cnt;
    }
}

public static class 이중우선순위큐
{
    public static int[] solution(string[] arguments)
    {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        int max = -987654321;
        int min = 987654321;
        foreach (string cmd in arguments)
        {
            string[] str = cmd.Split(' ');
            if (str[0].Equals("I"))
            {
                int num = int.Parse(str[1]);
                dic.Add(num, 1);
                if (num > max)
                {
                    max = num;
                }

                if (num < min)
                {
                    min = num;
                }

            }
            else if (dic.Count() > 0 && str[1] == "1")
            {
                dic.Remove(max);
                max = dic.Count > 0 ? dic.Keys.ToList().Max() : -987654321;
                min = dic.Count > 0 ? dic.Keys.ToList().Min() : 987654321;

            }
            else if (dic.Count() > 0 && str[1] == "-1")
            {
                dic.Remove(min);
                max = dic.Count > 0 ? dic.Keys.ToList().Max() : -987654321;
                min = dic.Count > 0 ? dic.Keys.ToList().Min() : 987654321;
          
            }
        }
        return dic.Count() == 0 ? new int[] { 0, 0 } : new int[] { dic.Keys.Max(), dic.Keys.Min() };
    }
}

    public static class 방문_길이
{
    public static int solution(string dirs)
    {
        bool[,,,] check = new bool[11, 11, 11, 11];
        char[] charArr = dirs.ToCharArray();
        int count = 0;
        int posX = 5;
        int posY = 5;


        for (int i = 0; i < dirs.Length && count < 181; i++)
        {
            int nx = posX;
            int ny = posY;
            switch (charArr[i])
            {
                case 'U':
                    ny++;
                    break;
                case 'D':
                    ny--;
                    break;
                case 'R':
                    nx++;
                    break;
                default:
                    nx--;
                    break;
            }
            if (nx > 10 || nx < 0 || ny > 10 || ny < 0) continue;
            if (!check[posX,posY,nx,ny])
            {
                check[posX, posY, nx, ny] = true;
                check[nx, ny, posX, posY] = true;
                count++;
            }
            posX = nx;
            posY = ny;
        }
        return count;
    }
}


public static class 가장_먼_노드
{
    public static int solution(int n, int[,] edge)
    {
        int[] dist = new int[n + 1];
        bool[,] map = new bool[n + 1, n + 1];
        // int [][] map = new int[n+1][n+1];
        for (int i = 0; i < edge.GetLength(0); i++)
        {
            map[edge[i,0], edge[i,1]] = map[edge[i,1], edge[i,0]] = true;
            //map[edge[i][0]][edge[i][1]] = map[edge[i][1]][edge[i][0]] = 1; // 이렇게 수행하면 에러남..
        }

        Queue<int> nodes = new Queue<int>();
        nodes.Enqueue(1);

        // BFS 탐색
        int maxDist = 0;
        while (!(nodes.Count == 0))
        {
            int i = nodes.Dequeue();

            for (int j = 2; j <= n; j++)
            {
                if (dist[j] == 0 && map[i, j])
                {
                    dist[j] = dist[i] + 1;
                    nodes.Enqueue(j);
                    maxDist = Math.Max(maxDist, dist[j]);
                }
            }
        }

        // 가장 멀리 있는 노드가 몇 개인지 계산
        int count = 0;
        foreach (int d in dist)
        {
            if (maxDist == d)
                count++;
        }

        return count;
    }
}



public static class 네트워크
{

    public static int solution(int n, int[,] computers)
    {
        int answer = 0;
        bool[] detected = new bool[n];
        Queue<int> searchNode = new Queue<int>();
        searchNode.Enqueue(0);
        for (int i = 0; i < n; i++)
        {
            if (!detected[i]) searchNode.Enqueue(i);
            else continue;
            while (searchNode.Count > 0)
            {
                int crtNode = searchNode.Dequeue();
                detected[crtNode] = true;
                for (int j = 0; j < n; j++)
                {
                    if (!detected[j] && computers[crtNode, j] == 1)
                    {
                        searchNode.Enqueue(j);
                    }
                }

            }
            answer++;
        }

        for (int i = 0; i < detected.Length && !detected[i]; i++)
        {
            answer++;
        }
        return answer;
    }
}


public class 섬_연결하기
{

    //부모 노드를 찾는 함수
    int GetParent(int[] parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = GetParent(parent, parent[node]);
    }

    //부모 노드를 합치는 함수
    void UnionParent(int[] parent, int a, int b) {
        a = GetParent(parent, a);
        b = GetParent(parent, b);
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }

    //같은 부모를 공유하는지 확인
    bool CheckShareParent(int[] parent, int a, int b) {
        a = GetParent(parent, a);
        b = GetParent(parent, b);
        if (a == b) return true;
        else return false;
    }

    int solution(int n, int[,] costs)
    {
        int answer = 0;
        int[][] cost = new int[costs.GetLength(0)][];
        int[] parent = new int[n];

        //convert 2d array to jagged array
        for (int i = 0; i < costs.GetLength(0); i++)
        {
            cost[i] = new int[costs.GetLength(1)];
            for (int j = 0; j < costs.GetLength(1); j++)
            {
                cost[i][j] = costs[i, j];
            }
        }
        var a = cost.OrderBy(x => x[2]).ToArray();

        for (int i = 0; i < parent.Length; i++)
        {
            parent[i] = i;
        }


        for (int i = 0; i < a.Length; i++)
        {
            if (!CheckShareParent(parent, a[i][0], a[i][1]))
            {
                UnionParent(parent, a[i][0], a[i][1]);
                answer += a[i][2];
            }
        }
        return answer;
    }
}

public static class 입국심사
{
    public static long solution(int n, int[] times)
    {
        long answer = 0;
        for (int i = 0; i < times.Length; i++)
        {
            answer += times[i];
        }
        answer = answer * n / (times.Length * times.Length);

        long[] worktime = new long[times.Length];

        long total = 0;
        for (int i = 0; i < times.Length; i++)
        {
            worktime[i] = answer / times[i];
            total += worktime[i];
        }

        long remind = n - total;

        int index = 0;
        while (remind > 0)
        {
            worktime[index]++;
            remind--;
        }

        for (int i = 0; i < worktime.Length; i++)
        {
            if (times[i] * worktime[i] > answer)
            {
                answer = times[i] * worktime[i];
            }
        }

        return answer;
    }
}


public static class 디스크_컨트롤러
{
    public static int solution(int[,] jobs)
    {
        int answer = 0;
        if (jobs.GetLength(0) == 0) return 0;



        int workUntil = jobs[0, 0] + jobs[0, 1];
        int workTime = jobs[0, 1] - jobs[0, 0];
        int index = 1;



        int[,] sortedBySecondElement = jobs.OrderBy(x => x[1]).OrderBy(x => x[0]);

        for (int i = 0; i < sortedBySecondElement.GetLength(0); i++)
        {
            for (int j = 0; j < sortedBySecondElement.GetLength(1); j++)
            {
                Console.WriteLine("i: {0} j: {1} arr[{0},{1}]: {2}", i, j, sortedBySecondElement[i, j]);
            }
        }


        return answer;
    }
}

public static class Sort {
    public static void SortDoubleDimension<T>(T[,] array, int sortType = 0)
    {
        int length = array.GetLength(0);
        T[] dim1 = new T[length];
        T[] dim2 = new T[length];
        for (int i = 0; i < length; i++)
        {
            dim1[i] = array[i, 0];
            dim2[i] = array[i, 1];
        }
        if (sortType == 0)
        {
            Array.Sort(dim1, dim2);
 
        }
        else if (sortType == 1)
        {
            Array.Sort(dim2, dim1);
        }
        else
        {
            Array.Sort(dim2, dim1);
            Array.Sort(dim1, dim2);
        }

        for (int i = 0; i < length; i++)
        {
            array[i, 0] = dim1[i];
            array[i, 1] = dim2[i];
        }
    }
}

public static class MultiDimensionalArrayExtensions
{
    /// <summary>
    ///   Orders the two dimensional array by the provided key in the key selector.
    /// </summary>
    /// <typeparam name="T">The type of the source two-dimensional array.</typeparam>
    /// <param name="source">The source two-dimensional array.</param>
    /// <param name="keySelector">The selector to retrieve the column to sort on.</param>
    /// <returns>A new two dimensional array sorted on the key.</returns>
    public static T[,] OrderBy<T>(this T[,] source, Func<T[], T> keySelector)
    {
        return source.ConvertToSingleDimension().OrderBy(keySelector).ConvertToMultiDimensional();
    }
    /// <summary>
    ///   Orders the two dimensional array by the provided key in the key selector in descending order.
    /// </summary>
    /// <typeparam name="T">The type of the source two-dimensional array.</typeparam>
    /// <param name="source">The source two-dimensional array.</param>
    /// <param name="keySelector">The selector to retrieve the column to sort on.</param>
    /// <returns>A new two dimensional array sorted on the key.</returns>
    public static T[,] OrderByDescending<T>(this T[,] source, Func<T[], T> keySelector)
    {
        return source.ConvertToSingleDimension().
            OrderByDescending(keySelector).ConvertToMultiDimensional();
    }
    /// <summary>
    ///   Converts a two dimensional array to single dimensional array.
    /// </summary>
    /// <typeparam name="T">The type of the two dimensional array.</typeparam>
    /// <param name="source">The source two dimensional array.</param>
    /// <returns>The repackaged two dimensional array as a single dimension based on rows.</returns>
    private static IEnumerable<T[]> ConvertToSingleDimension<T>(this T[,] source)
    {
        T[] arRow;

        for (int row = 0; row < source.GetLength(0); ++row)
        {
            arRow = new T[source.GetLength(1)];

            for (int col = 0; col < source.GetLength(1); ++col)
                arRow[col] = source[row, col];

            yield return arRow;
        }
    }
    /// <summary>
    ///   Converts a collection of rows from a two dimensional array back into a two dimensional array.
    /// </summary>
    /// <typeparam name="T">The type of the two dimensional array.</typeparam>
    /// <param name="source">The source collection of rows to convert.</param>
    /// <returns>The two dimensional array.</returns>
    private static T[,] ConvertToMultiDimensional<T>(this IEnumerable<T[]> source)
    {
        T[,] twoDimensional;
        T[][] arrayOfArray;
        int numberofColumns;

        arrayOfArray = source.ToArray();
        numberofColumns = (arrayOfArray.Length > 0) ? arrayOfArray[0].Length : 0;
        twoDimensional = new T[arrayOfArray.Length, numberofColumns];

        for (int row = 0; row < arrayOfArray.GetLength(0); ++row)
            for (int col = 0; col < numberofColumns; ++col)
                twoDimensional[row, col] = arrayOfArray[row][col];

        return twoDimensional;
    }
}