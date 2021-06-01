using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Dictionaries_and_Maps
    {
        static string[] DictionaryChecking(Dictionary<string, int> dic, string[] arr) {
            string[] answer = new string[arr.Length];

            int i = 0;
            try
            {
                while (i < arr.Length)
                {
                    if (dic.ContainsKey(arr[i]))
                    {
                        answer[i] = arr[i] + "=" + dic[arr[i]];
                    }
                    else
                    {
                        answer[i] = "Not found";
                    }
                }
            }
            catch (Exception)
            {

                return answer;
            }

            
            return answer;
        }

        //3
        //sam 99912222
        //tom 11122222
        //harry 12299933
        //sam
        //edward
        //harry
        static void Main(String[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            Dictionary<string, int> contacts = new Dictionary<string, int>();
            for (int i = 0; i < n; i++)
            {
               var temp = Console.ReadLine().Split(' ');
                if (!contacts.ContainsKey(temp[0]))
                {
                    contacts.Add(temp[0], Convert.ToInt32(temp[1]));
                }
            }

            string[] arr = new string[n];
            for (int i = 0; i < n; i++)
            {
                arr[i] = Console.ReadLine();
            }

            arr = DictionaryChecking(contacts, arr);

            for (int i = 0; i < arr.Length; i++)
            {
                Console.WriteLine(arr[i]);
            }

        }
    }
}
