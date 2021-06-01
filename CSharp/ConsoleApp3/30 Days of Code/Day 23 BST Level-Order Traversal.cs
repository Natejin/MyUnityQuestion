using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_23_BST_Level_Order_Traversal
    {
        class Node
        {
            public Node left, right;
            public int data;
            public Node(int data)
            {
                this.data = data;
                left = right = null;
            }
        }

        static void levelOrder(Node root)
        {
            Queue<Node> queue = new Queue<Node>();
            queue.Enqueue(root);
            while (queue.Count > 0)
            {
                Node dequeue = queue.Dequeue();
                if (dequeue.left != null) queue.Enqueue(dequeue.left);
                if (dequeue.right != null) queue.Enqueue(dequeue.right);
                Console.Write(dequeue.data + " ");
            }
        }

        static Node insert(Node root, int data)
        {
            if (root == null)
            {
                return new Node(data);
            }
            else
            {
                Node cur;
                if (data <= root.data)
                {
                    cur = insert(root.left, data);
                    root.left = cur;
                }
                else
                {
                    cur = insert(root.right, data);
                    root.right = cur;
                }
                return root;
            }
        }
        static void Main(String[] args)
        {
            Node root = null;
            int T = Int32.Parse(Console.ReadLine());
            while (T-- > 0)
            {
                int data = Int32.Parse(Console.ReadLine());
                root = insert(root, data);
            }
            levelOrder(root);

        }
    }
}
