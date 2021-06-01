using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace ConsoleApp3.Algorithms.Implementation.Easy
{
    class Designer_PDF_Viewer
    {
        static int designerPdfViewer(int[] h, string word)
        {
            int currentlyHigh = 0;
            for (int i = 0; i < word.Length; i++)
                if (h[word[i] - 97] > currentlyHigh)
                    currentlyHigh = h[word[i] - 97];
            return currentlyHigh * word.Length;
        }

        static int designerPdfViewer1(int[] h, string word)
        {
            Dictionary<char, int> tempDic = new Dictionary<char, int>();
            for (int i = 0; i < h.Length; i++)
            {
                tempDic.Add((char)(i + 97), h[i]);
                Console.WriteLine((char)(i + 97));
            }

            char[] wordChar = word.ToCharArray();
            int currentlyHigh = 0;
            for (int i = 0; i < wordChar.Length; i++)
            {
                if (tempDic[wordChar[i]] > currentlyHigh)
                {
                    currentlyHigh = tempDic[wordChar[i]];
                }

            }
            Console.WriteLine("temp {0}, length {1}", currentlyHigh, word.Length);
            return currentlyHigh * word.Length;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int[] h = Array.ConvertAll(Console.ReadLine().Split(' '), hTemp => Convert.ToInt32(hTemp))
            ;
            string word = Console.ReadLine();

            int result = designerPdfViewer(h, word);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
