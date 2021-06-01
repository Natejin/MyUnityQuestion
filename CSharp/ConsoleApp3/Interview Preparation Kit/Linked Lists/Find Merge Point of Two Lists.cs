using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using static ConsoleApp3.Interview_Preparation_Kit.Linked_Lists.LinkedList_Reference;
namespace ConsoleApp3.Interview_Preparation_Kit.Linked_Lists
{
    class Find_Merge_Point_of_Two_Lists
    {
        static int findMergeNode(SinglyLinkedListNode head1, SinglyLinkedListNode head2)
        {
            Dictionary<SinglyLinkedListNode, bool> tempDic = new Dictionary<SinglyLinkedListNode, bool>();
            SinglyLinkedListNode temp = head1;
            while (temp != null)
            {
                tempDic.Add(temp, true);
                temp = temp.next;
            }

            temp = head2;
            while (temp != null)
            {
                if (tempDic.ContainsKey(temp))
                {
                    return temp.data;
                }
                else {
                    temp = temp.next;
                }
            }
            return -1;
        }


        static int findMergeNode1(SinglyLinkedListNode head1, SinglyLinkedListNode head2)
        {
            SinglyLinkedListNode current1 = head1;

            while (current1 != null)
            {
                SinglyLinkedListNode current2 = head2;

                while (current2 != null)
                {
                    if (current1 == current2)
                        return current1.data;

                    current2 = current2.next;
                }

                current1 = current1.next;
            }

            return -1;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int tests = Convert.ToInt32(Console.ReadLine());

            for (int testsItr = 0; testsItr < tests; testsItr++)
            {
                int index = Convert.ToInt32(Console.ReadLine());

                SinglyLinkedList llist1 = new SinglyLinkedList();

                int llist1Count = Convert.ToInt32(Console.ReadLine());

                for (int i = 0; i < llist1Count; i++)
                {
                    int llist1Item = Convert.ToInt32(Console.ReadLine());
                    llist1.InsertNode(llist1Item);
                }

                SinglyLinkedList llist2 = new SinglyLinkedList();

                int llist2Count = Convert.ToInt32(Console.ReadLine());

                for (int i = 0; i < llist2Count; i++)
                {
                    int llist2Item = Convert.ToInt32(Console.ReadLine());
                    llist2.InsertNode(llist2Item);
                }

                SinglyLinkedListNode ptr1 = llist1.head;
                SinglyLinkedListNode ptr2 = llist2.head;

                for (int i = 0; i < llist1Count; i++)
                {
                    if (i < index)
                    {
                        ptr1 = ptr1.next;
                    }
                }

                for (int i = 0; i < llist2Count; i++)
                {
                    if (i != llist2Count - 1)
                    {
                        ptr2 = ptr2.next;
                    }
                }

                ptr2.next = ptr1;

                int result = findMergeNode(llist1.head, llist2.head);

                textWriter.WriteLine(result);
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
