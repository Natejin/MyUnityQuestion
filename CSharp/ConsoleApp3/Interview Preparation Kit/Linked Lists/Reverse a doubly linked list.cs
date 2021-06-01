using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using static ConsoleApp3.Interview_Preparation_Kit.Linked_Lists.LinkedList_Reference;

namespace ConsoleApp3.Interview_Preparation_Kit.Linked_Lists
{
    class Reverse_a_doubly_linked_list
    {
        static DoublyLinkedListNode reverse(DoublyLinkedListNode head)
        {
            DoublyLinkedListNode nextNode = head;

            while (true)
            {
                DoublyLinkedListNode temp = nextNode.next;
                nextNode.next = nextNode.prev;
                nextNode.prev = temp;
                if (nextNode.prev != null)
                {
                    nextNode = nextNode.prev;
                }
                else {

                    break;
                }

            }
            return nextNode;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int t = Convert.ToInt32(Console.ReadLine());

            for (int tItr = 0; tItr < t; tItr++)
            {
                DoublyLinkedList llist = new DoublyLinkedList();

                int llistCount = Convert.ToInt32(Console.ReadLine());

                for (int i = 0; i < llistCount; i++)
                {
                    int llistItem = Convert.ToInt32(Console.ReadLine());
                    llist.InsertNode(llistItem);
                }

                DoublyLinkedListNode llist1 = reverse(llist.head);

                PrintDoublyLinkedList(llist1, " ", textWriter);
                textWriter.WriteLine();
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
