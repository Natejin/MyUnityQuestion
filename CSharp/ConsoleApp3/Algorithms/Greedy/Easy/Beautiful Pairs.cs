using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Easy
{
    class Beautiful_Pairs
    {
        static int beautifulPairs(int[] A, int[] B)
        {

            List<int> AList = A.ToList();
            List<int> BList = B.ToList();
            List<int> XList = new List<int>();
            for (int i =A.Length -1; i >= 0; i--)
            {
                if (BList.Contains(A[i]))
                {
                    AList.Remove(A[i]);
                    BList.Remove(A[i]);
                    XList.Add(A[i]);
                }
            }

            return XList.Count == A.Length ? A.Length - 1 : XList.Count + 1;

        }
        //4
        //1 2 3 4
        //1 2 3 3
        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            int[] A = Array.ConvertAll(Console.ReadLine().Split(' '), ATemp => Convert.ToInt32(ATemp))
            ;

            int[] B = Array.ConvertAll(Console.ReadLine().Split(' '), BTemp => Convert.ToInt32(BTemp))
            ;
            int result = beautifulPairs(A, B);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
