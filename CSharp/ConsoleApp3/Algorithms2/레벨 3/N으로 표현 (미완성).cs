using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    class N으로_표현
    {
        public int solution(int n, int num)
        {
			int ans = 0;
			List<List<int>> list = new List<List<int>>();
			List<int> set = new List<int>();
			set.Add(n);
			list.Add(set);

			//while (ans < 8)
			//{
			//	if (list[ans].Contains(num)) break;
			//	ans++;

			//	List<int> nset = new List<int>();
			//	string s = "";
			//	for (int i = 0; i < ans + 1; i++) {
			//		s += n;
			//		nset.Add(Convert.ToInt32(s));
			//	}

			//	for (int i = 0; i <= ans / 2; i++)
			//	{
			//		for (int j = 0; i + j < ans; j++)
			//		{
			//			for (Iterator it1 = list[i].iterator(); it1.hasNext();)
			//			{
			//				int op1 = (int)it1.next();
			//				for (Iterator it2 = list.get(j).iterator(); it2.hasNext();)
			//				{
			//					int op2 = (int)it2.next();
			//					nset.Add(op1 + op2);
			//					nset.Add(op1 - op2);
			//					nset.Add(op1 * op2);
			//					if (op2 != 0) nset.Add(op1 / op2);
			//				}
			//			}
			//		}
			//	}
			//	list.Add(nset);
			//}

			return (ans >= 8) ? -1 : ans + 1;
		}
    }
}
