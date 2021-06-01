using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation.Medium
{
    class Climbing_the_Leaderboard
    {
        static int[] climbingLeaderboard(int[] scores, int[] alice)
        {
            var scoreArr = scores.Distinct().OrderBy(x => x).ToArray();
            int[] answer = new int[alice.Length];
            for (int i = 0; i < alice.Length; i++)
            {
                answer[i] = Array.BinarySearch(scoreArr, alice[i]);
                Console.WriteLine("alic[i] {0}, answer {1}", alice[i], answer[i]);
                if (answer[i] < 0)
                {
                    answer[i] = scoreArr.Length - Math.Abs(answer[i]) + 2;
                }
                else {
                    answer[i] = scoreArr.Length - answer[i];
                }
            }


            return answer;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int scoresCount = Convert.ToInt32(Console.ReadLine());

            int[] scores = Array.ConvertAll(Console.ReadLine().Split(' '), scoresTemp => Convert.ToInt32(scoresTemp))
            ;
            int aliceCount = Convert.ToInt32(Console.ReadLine());

            int[] alice = Array.ConvertAll(Console.ReadLine().Split(' '), aliceTemp => Convert.ToInt32(aliceTemp))
            ;
            int[] result = climbingLeaderboard(scores, alice);

            textWriter.WriteLine(string.Join("\n", result));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
