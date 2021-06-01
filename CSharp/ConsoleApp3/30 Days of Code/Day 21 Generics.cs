using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_21_Generics
    {
		static void PrintArray<T>(T[] input) {
			for (int i = 0; i < input.Length; i++)
			{
				Console.WriteLine(input[i]);
			}
		}

		static void Main(string[] args)
		{
			int n = Convert.ToInt32(Console.ReadLine());
			int[] intArray = new int[n];
			for (int i = 0; i < n; i++)
			{
				intArray[i] = Convert.ToInt32(Console.ReadLine());
			}

			n = Convert.ToInt32(Console.ReadLine());
			string[] stringArray = new string[n];
			for (int i = 0; i < n; i++)
			{
				stringArray[i] = Console.ReadLine();
			}

			PrintArray<Int32>(intArray);
			PrintArray<String>(stringArray);
		}
	}
}
