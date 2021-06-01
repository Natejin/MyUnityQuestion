using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_12_Inheritance
    {

        class Person {



        }

        class Student : Person
        {
            public string firstName;
            public string lastName;
            public int id;
            private int[] testScores;

            public Student(string firstName, string lastName, int id, int[] testScores)
            {
                this.firstName = firstName;
                this.lastName = lastName;
                this.id = id;
                this.testScores = testScores;
            }

            public string Calculate()
            {
                int sum = 0;
                for (int i = 0; i < testScores.Length; i++)
                {
                    sum += testScores[i];
                }
                sum = sum / testScores.Length;
                if (sum >= 90)
                {
                    return "O";
                }
                else if (sum >= 80)
                {
                    return "E";
                }
                else if (sum >= 70)
                {
                    return "A";
                }
                else if (sum >= 55)
                {
                    return "P";
                }
                else if (sum >= 40)
                {
                    return "D";
                }
                else {
                    return "T";
                }
            }


            public void printPerson() {
                Console.WriteLine("Name: {0}, {1}\nID: {2}", firstName, lastName, id);
            }
        }

        static void Main()
		{
			string[] inputs = Console.ReadLine().Split();
			string firstName = inputs[0];
			string lastName = inputs[1];
			int id = Convert.ToInt32(inputs[2]);
			int numScores = Convert.ToInt32(Console.ReadLine());
			inputs = Console.ReadLine().Split();
			int[] scores = new int[numScores];
			for (int i = 0; i < numScores; i++)
			{
				scores[i] = Convert.ToInt32(inputs[i]);
			}

			Student s = new Student(firstName, lastName, id, scores);
			s.printPerson();
			Console.WriteLine("Grade: " + s.Calculate() + "\n");
		}
	}
}
