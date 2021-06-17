using System;
using System.Linq;
using System.Collections.Generic;



namespace 프로그래머스
{
	public class Solution3
	{
		int[] ch = new int[201];

		void DFS(int[,] v, int idx)
		{

			for (int i = 0; i < idx; i++)
			{
				if (v[idx, i] == 1 && ch[i] == 0)
				{
					//연결 && 방문하지 않은 노드
					ch[i] = 1;
					DFS(v, i);
				}
			}
		}

		public int solution(int n, int[,] v)
		{
			int answer = 0;

			for (int i = 0; i < n; i++)
			{
				if (ch[i] == 0)
				{
					DFS(v, i);
					answer++;
				}
			}
			return answer;
		}
	}

	public class Solution
	{
		public Dictionary<int, int> save = new Dictionary<int, int>();

		//프로그래밍시 save에저장할 값을 생성 하는 함수
		public void CreateValue(int n)
		{
			int[] dp = new int[n + 1];

			dp[0] = 1;
			dp[1] = 1;

			for (int i = 2; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					dp[i] += dp[i - j] * dp[j - 1];
					save.Add(i, dp[i]);
				}
			}

		}

		//실제 프로그램 가동시 n을 받아서 딕셔러리에 저장된값 리턴
		public int solution(int n)
		{
			return save[n];
		}
	}



	namespace Solution
	{
		public class Solution
		{

			public static Dictionary<string, int> AverageAgeForEachCompany(List<Employee> employees)
			{
				Dictionary<string, List<Employee>> dic = new Dictionary<string, List<Employee>>();
				Dictionary<string, int> dic2 = new Dictionary<string, int>();
				for (int i = 0; i < employees.Count; i++)
				{
					if (!dic.ContainsKey(employees[i].Company))
					{
						var temp = new List<Employee>();
						temp.Add(employees[i]);
						dic.Add(employees[i].Company, temp);
					}
					else
					{
						dic[employees[i].Company].Add(employees[i]);
					}
				}

				foreach (var item in dic)
				{
					int temp = 0;

					for (int i = 0; i < item.Value.Count; i++)
					{
						temp += item.Value[i].Age;
					}
					temp = int.Parse(Math.Ceiling(((float)temp / item.Value.Count)).ToString());
					dic2.Add(item.Key, temp);
				}


				dic2 = dic2.OrderBy(obj => obj.Key).ToDictionary(obj => obj.Key, obj => obj.Value);
				return dic2;
			}

			public static Dictionary<string, int> CountOfEmployeesForEachCompany(List<Employee> employees)
			{
				Dictionary<string, int> dic = new Dictionary<string, int>();
				for (int i = 0; i < employees.Count; i++)
				{
					if (!dic.ContainsKey(employees[i].Company))
					{
						dic.Add(employees[i].Company, 1);
					}
					else
					{
						dic[employees[i].Company] += 1;
					}
				}
				dic = dic.OrderBy(obj => obj.Key).ToDictionary(obj => obj.Key, obj => obj.Value);
				return dic;
			}

			public static Dictionary<string, Employee> OldestAgeForEachCompany(List<Employee> employees)
			{
				Dictionary<string, Employee> dic = new Dictionary<string, Employee>();
				for (int i = 0; i < employees.Count; i++)
				{
					if (!dic.ContainsKey(employees[i].Company))
					{
						dic.Add(employees[i].Company, employees[i]);
					}
					else
					{
						if (dic[employees[i].Company].Age < employees[i].Age)
						{
							dic[employees[i].Company] = employees[i];
						}
						else if (dic[employees[i].Company].Age == employees[i].Age)
						{
							if (string.Compare(dic[employees[i].Company].LastName, employees[i].LastName) == 1)
							{
								dic[employees[i].Company] = employees[i];
							}

							if (string.Compare(dic[employees[i].Company].LastName, employees[i].LastName) == 0)
							{
								if (string.Compare(dic[employees[i].Company].FirstName, employees[i].FirstName) == 1)
								{
									dic[employees[i].Company] = employees[i];
								}
							}
						}

					}
				}
				dic = dic.OrderBy(obj => obj.Key).ToDictionary(obj => obj.Key, obj => obj.Value);
				return dic;
			}

			public static void Main()
			{
				int countOfEmployees = int.Parse(Console.ReadLine());

				var employees = new List<Employee>();

				for (int i = 0; i < countOfEmployees; i++)
				{
					string str = Console.ReadLine();
					string[] strArr = str.Split(' ');
					employees.Add(new Employee
					{
						FirstName = strArr[0],
						LastName = strArr[1],
						Company = strArr[2],
						Age = int.Parse(strArr[3])
					});
				}

				foreach (var emp in AverageAgeForEachCompany(employees))
				{
					Console.WriteLine($"The average age for company {emp.Key} is {emp.Value}");
				}

				foreach (var emp in CountOfEmployeesForEachCompany(employees))
				{
					Console.WriteLine($"The count of employees for company {emp.Key} is {emp.Value}");
				}

				foreach (var emp in OldestAgeForEachCompany(employees))
				{
					Console.WriteLine($"The oldest employee of company {emp.Key} is {emp.Value.FirstName} {emp.Value.LastName} having age {emp.Value.Age}");
				}
			}
		}

		public class Employee
		{
			public string FirstName { get; set; }
			public string LastName { get; set; }
			public int Age { get; set; }
			public string Company { get; set; }
		}
	}


	namespace Solution
	{

		public class NotesStore
		{
			List<string> completed = new List<string>();
			List<string> active = new List<string>();
			List<string> other = new List<string>();
			public NotesStore() { }
			public void AddNote(String state, String name)
			{
				if (name == "")
				{
					Console.WriteLine("Name cannot be empty");
				}
				if (state != "completed" || state != "active" || state != "other")
				{
					Console.WriteLine("Invalid state {" + state + "}");
				}
				if (true)
				{

				}
			}
			public List<String> GetNotes(String state)
			{
				if (state != "completed" || state != "active" || state != "other")
				{
					Console.WriteLine("Invalid state {" + state + "}");
				}
				if (state == "completed")
				{
					return completed;
				}
				if (state == "completed")
				{
					return completed;
				}
				if (state == "completed")
				{
					return completed;
				}
			}
		}

		public class Solution
		{




			public static void Main()
			{
				var notesStoreObj = new NotesStore();
				var n = int.Parse(Console.ReadLine());
				for (var i = 0; i < n; i++)
				{
					var operationInfo = Console.ReadLine().Split(' ');
					try
					{
						if (operationInfo[0] == "AddNote")
							notesStoreObj.AddNote(operationInfo[1], operationInfo.Length == 2 ? "" : operationInfo[2]);
						else if (operationInfo[0] == "GetNotes")
						{
							var result = notesStoreObj.GetNotes(operationInfo[1]);
							if (result.Count == 0)
								Console.WriteLine("No Notes");
							else
								Console.WriteLine(string.Join(",", result));
						}
						else
						{
							Console.WriteLine("Invalid Parameter");
						}
					}
					catch (Exception e)
					{
						Console.WriteLine("Error: " + e.Message);
					}
				}
			}
		}
	}
}


public class Solution
{
	public string solution(string s)
	{
		string answer;
		var a = s.Split(' ');
		List<int> test = new List<int>();
		for (int i = 0; i < a.Length; i++)
		{
			test.Add(int.Parse(a[i]));
		}
		//test = test.OrderBy(x => x).ToList();
		test.Sort();
		answer = test[0].ToString() + " " + test[test.Count - 1].ToString();
		return answer;
	}

	public int[] solution2(int n, string[] words)
	{
		int[] answer = new int[2];
		Dictionary<string, bool> dic = new Dictionary<string, bool>();
		char previousChar = words[0][0];
		for (int i = 0; i < words.Length; i++)
		{

			if (!dic.ContainsKey(words[i]) && previousChar == words[i][0])
			{
				dic.Add(words[i], false);
				previousChar = words[i][words[i].Length - 1];
			}
			else
			{
				answer[0] = i / n;
				answer[1] = i % n;
				return answer;
			}

		}
		return answer;
	}

	public int solution1(int[] a, int[] b)
	{
		int answer = 0;
		for (int i = 0; i < a.Length; i++)
		{
			answer += a[i] * b[i];
		}

		return answer;
	}

	public int[] solution(int[] lottos, int[] win_nums)
	{
		int[] answer = new int[] { };
		List<int> winNum = win_nums.ToList();
		int randomNum = 0;
		int winNumber = 0;
		for (int i = 0; i < lottos.Length; i++)
		{
			if (lottos[i] == 0)
			{
				randomNum++;
			}
			else if (winNum.Contains(lottos[i]))
			{
				winNumber++;
			}

		}

		answer[0] = 7 - (randomNum + winNumber);
		answer[1] = 7 - (winNumber);
		for (int i = 0; i < answer.Length; i++)
		{
			if (answer[i] == 7)
			{
				answer[i] = 6;
			}
		}
		return answer;
	}
}
}


namespace Programmers
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }

    public class 야근지수
    {
        public long solution(int n, int[] works)
        {
            long answer = 0;
            var a = works.ToList().OrderBy(x => x).ToArray();
            int remain = n;
            int sameIndex = 0;
            for (int i = 0; i < works.Length; i++)
            {
                int j = i + 1;
                if (j < works.Length)
                {
                    //works[i]와 works[j]가 같으면 그다음으로 이동
                    if (works[j] == works[i])
                    {
                        continue;
                    }
                    //works[i]가 works[j]보다 크면 그차이만큼 삭제
                    else
                    {
                        if (remain - (works[i] - works[j]) * (i + 1) > 0)
                        {
                            remain -= (works[i] - works[j]) * (i + 1);
                        }
                        //같을경우 포문 종료
                        else if (remain - (works[i] - works[j]) * (i + 1) == 0)
                        {
                            remain -= (works[i] - works[j]) * (i + 1);
                            sameIndex = i;
                            break;
                        }
                        //더 클경우
                        else
                        {
                           
                        }
                    }
                }
                else
                {
                    sameIndex = j;
                }
            }
            answer += works[sameIndex] * works[sameIndex] * (sameIndex + 1);
            for (int i = sameIndex + 1; i < works.Length; i++)
            {
                answer += works[i] * works[i];
            }
            return answer;
        }
    }
}
// works[0] = 10  j = 1
// works[1] = 10  j = 2
// works[2] = 9