using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Midium
{
    class Equal
    {
        static int equal1(int[] arr) {
            Array.Sort(arr);

            int sum = int.MaxValue;

            for (int b = 0; b < 3; b++)
            {
                int current_sum = 0;
                for (int i = 0; i < arr.Length; i++)
                {
                    int delta = arr[i] - arr[0] + b;
                    Console.WriteLine("b {0} delat {1} arr[i] {2} arr[0] {3} current_sum {4}", b, delta, arr[i], arr[0], current_sum);
                    current_sum += (int)delta / 5 + delta % 5 / 2 + delta % 5 % 2 / 1;
                    Console.WriteLine("count {0} ", (int)delta / 5 + delta % 5 / 2 + delta % 5 % 2 / 1);
                }
                sum = Math.Min(current_sum, sum);
            }

            return sum;
        }

        static int equal(int[] arr)
        {
            Array.Sort(arr);
            int sum = 0;
            int count = 0;
            for (int i = 0; i < arr.Length - 2; i++)
            {
                arr[i + 1] += sum;
                if (arr[i] == arr[i + 1]) continue;
                int dif = arr[i + 1] - arr[i];
                while (dif == 0)
                {
                    if (dif > 5)
                    {
                        switch (dif)
                        {
                            case 5:
                                sum += 5;
                                count++;
                                break;
                            case 4:
                                sum += 4;
                                count +=2;
                                break;
                            case 3:
                                sum += 3;
                                count += 2;
                                break;
                            case 2:
                                sum += 2;
                                count++;
                                break;
                            default:
                                sum += 1;
                                count++;
                                break;
                        }
                        break;
                    }
                    else {
                        sum += 5;
                        dif -= 5;
                    }
                }
            }
            return count;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());

                int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp))
                ;
                int result = equal(arr);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
