using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_24_More_Linked_Lists
    {
		class Node
		{
			public int data;
			public Node next;
			public Node(int d)
			{
				data = d;
				next = null;
			}

		}

		static Node removeDuplicates(Node head)
		{
			Dictionary<int, Node> tempdic = new Dictionary<int, Node>();
			tempdic.Add(head.data, head);
			Node current = head;
			while (current.next != null)
			{
				if (!tempdic.ContainsKey(current.next.data))
				{
					tempdic.Add(current.next.data, current);
					current = current.next;
				}
				else
				{
					current.next = current.next.next;
					
				}
			}
			return head;


 		}

		static Node insert(Node head, int data)
		{
			Node p = new Node(data);


			if (head == null)
				head = p;
			else if (head.next == null)
				head.next = p;
			else
			{
				Node start = head;
				while (start.next != null)
					start = start.next;
				start.next = p;

			}
			return head;
		}
	 static void display(Node head)
		{
			Node start = head;
			while (start != null)
			{
				Console.Write(start.data + " ");
				start = start.next;
			}
		}
		static void Main(String[] args)
		{

			Node head = null;
			int T = Int32.Parse(Console.ReadLine());
			while (T-- > 0)
			{
				int data = Int32.Parse(Console.ReadLine());
				head = insert(head, data);
			}
			head = removeDuplicates(head);
			display(head);
		}
	}
}
