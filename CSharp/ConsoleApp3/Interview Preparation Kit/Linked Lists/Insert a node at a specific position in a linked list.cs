using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;
using static ConsoleApp3.Interview_Preparation_Kit.Linked_Lists.LinkedList_Reference;

namespace ConsoleApp3.Interview_Preparation_Kit.Linked_Lists
{

       

class Insert_a_node_at_a_specific_position_in_a_linked_list
    {

       

        // Complete the insertNodeAtPosition function below.

        /*
         * For your reference:
         *
         * SinglyLinkedListNode {
         *     int data;
         *     SinglyLinkedListNode next;
         * }
         *
         */
        static SinglyLinkedListNode insertNodeAtPosition(SinglyLinkedListNode head, int data, int position)
        {
            int index = 0;
            SinglyLinkedListNode target = head;
            while (position >= index)
            {
                target = target.next;
                index++;
            }
            SinglyLinkedListNode insert = new SinglyLinkedListNode(data);

            SinglyLinkedListNode nextNode = target.next;
            target.next = insert;
            insert.next = nextNode;
            return head;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            SinglyLinkedList llist = new SinglyLinkedList();

            int llistCount = Convert.ToInt32(Console.ReadLine());

            for (int i = 0; i < llistCount; i++)
            {
                int llistItem = Convert.ToInt32(Console.ReadLine());
                llist.InsertNode(llistItem);
            }

            int data = Convert.ToInt32(Console.ReadLine());

            int position = Convert.ToInt32(Console.ReadLine());

            SinglyLinkedListNode llist_head = insertNodeAtPosition(llist.head, data, position);

            PrintSinglyLinkedList(llist_head, " ", textWriter);
            textWriter.WriteLine();

            textWriter.Flush();
            textWriter.Close();
        }
    }

}

