using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Interview_Preparation_Kit.Stacks_and_Queues
{
    class Min_Max_Riddle
    {

        static long[] riddle(long[] arr)
        {
            // complete the function
            int n = arr.Length;
            Stack<long> st = new Stack<long>();
            long[] left = new long[n + 1];
            long[] right = new long[n + 1];
            for (int i = 0; i < n; i++)
            {
                left[i] = -1;
                while (st.Count != 0 && arr[st.Peek()] >= arr[i])
                    st.Pop();

                if (st.Count != 0)
                    left[i] = st.Peek();

                st.Push(i);
            }
            st.Clear();

            for (int i = n - 1; i >= 0; i--)
            {
                right[i] = n;
                while (st.Count != 0 && arr[st.Peek()] >= arr[i])
                    st.Pop();

                if (st.Count != 0)
                    right[i] = st.Peek();

                st.Push(i);
            }

            long[] ans = new long[n + 1];
            for (int i = 0; i < n; i++)
            {
                long len = right[i] - left[i] - 1;
                ans[len] = Math.Max(ans[len], arr[i]);
            }
            for (int i = n - 1; i >= 1; i--)
            {
                ans[i] = Math.Max(ans[i], ans[i + 1]);
            }
            long[] res = new long[n];
            for (int i = 1; i <= n; i++)
            {
                res[i - 1] = ans[i];
            }
            return res;

        }

    
        // Complete the riddle function below.
        static long[] riddle1(long[] arr)
        {
            long[] answer = new long[arr.Length];
            long[] temp1 = new long[arr.Length];
            Array.Copy(arr, temp1, arr.Length);
            long[] temp2 = new long[arr.Length - 1];
            int index = 0;


            while (index < arr.Length)
            {
                long max = temp1[0];
                int length = temp2.Length - index;
                for (int i = 0; i < length; i++)
                {
                    temp2[i] = Math.Min(temp1[i], temp1[i + 1]);
                    if (max < temp1[i + 1])
                    {
                        max = temp1[i + 1];
                    }
                }
                answer[index] = max;
                Array.Copy(temp2, temp1, length);
                index++;

            }
            return answer;
        }

        static void Maain(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            long[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt64(arrTemp))
            ;
            long[] res = riddle(arr);

            textWriter.WriteLine(string.Join(" ", res));

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
