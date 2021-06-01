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
using System.Reflection.Metadata.Ecma335;
using static ConsoleApp3.Interview_Preparation_Kit.Linked_Lists.LinkedList_Reference;

namespace ConsoleApp3.Interview_Preparation_Kit.Linked_Lists
{
    class Inserting_a_Node_Into_a_Sorted_Doubly_Linked_List
    {
        

        // Complete the sortedInsert function below.

        /*
         * For your reference:
         *
         * DoublyLinkedListNode {
         *     int data;
         *     DoublyLinkedListNode next;
         *     DoublyLinkedListNode prev;
         * }
         *
         */
        static DoublyLinkedListNode sortedInsert(DoublyLinkedListNode head, int data)
        {
            DoublyLinkedListNode currentNode = head;
            while (currentNode != null)
            {
                Console.WriteLine("data {0}, next {1}", currentNode.data, currentNode.next.data);
                if (currentNode.data > data)
                {
                    DoublyLinkedListNode newNode = new DoublyLinkedListNode(data);
                    currentNode.prev = newNode;
                    newNode.next = currentNode;
                    head = newNode;
                    break;
                }
                else if (currentNode.data < data && currentNode.next.data > data)
                {
                    DoublyLinkedListNode next = currentNode.next;
                    DoublyLinkedListNode newNode = new DoublyLinkedListNode(data);
                    currentNode.next = newNode;
                    newNode.prev = currentNode;
                    next.prev = newNode;
                    newNode.next = next;
                    break;
                }
                else if (currentNode.next.next == null && currentNode.next.data < data)
                {
                    DoublyLinkedListNode newNode = new DoublyLinkedListNode(data);
                    currentNode.next.next = newNode;
                    newNode.prev = currentNode.next.next;
                    break;
                }
                else {
                    currentNode = currentNode.next;
                }
            }

            return head;

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

                int data = Convert.ToInt32(Console.ReadLine());

                DoublyLinkedListNode llist1 = sortedInsert(llist.head, data);

                PrintDoublyLinkedList(llist1, " ", textWriter);
                textWriter.WriteLine();
            }

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
