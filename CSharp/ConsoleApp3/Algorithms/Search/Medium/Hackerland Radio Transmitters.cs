using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Search.Medium
{
    class Hackerland_Radio_Transmitters
    {
        static int hackerlandRadioTransmitters(int[] x, int k)
        {
            Array.Sort(x);
            int numOfTransmitters = 0;
            int i = 0;
            int n = x.Length;
            while (i < n)
            {
                numOfTransmitters++;
                int loc = x[i] + k;
                while (i < n && x[i] <= loc) i++;
                loc = x[--i] + k;
                while (i < n && x[i] <= loc) i++;
            }
            return numOfTransmitters;
        }


        static int hackerlandRadioTransmitters1(int[] x, int k)
        {
            Array.Sort(x);
            Dictionary<int, bool> keyValuePairs = new Dictionary<int, bool>();
            for (int i = 0; i < x.Length; i++)
            {
                if (!keyValuePairs.ContainsKey(x[i]))
                {
                    keyValuePairs.Add(x[i], false);
                }
         
            }

            int limit = x[x.Length - 1];
            int count = 0;
            for (int i = 1; i <= limit; i++)
            {
                if (keyValuePairs.ContainsKey(i))
                {
                    int index = i + k;
                    while (index >= i)
                    {
                        Console.WriteLine("i {0}  index {1}", i, index);
                        if (keyValuePairs.ContainsKey(index))
                        {
                            count++;
                            i = index + k;
                            break;
                        }
                        else {
                            index--;
                        }
                    }
                }
            }
            return count;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            string[] nk = Console.ReadLine().Split(' ');

            int n = Convert.ToInt32(nk[0]);

            int k = Convert.ToInt32(nk[1]);

            int[] x = Array.ConvertAll(Console.ReadLine().Split(' '), xTemp => Convert.ToInt32(xTemp))
            ;
            int result = hackerlandRadioTransmitters(x, k);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
