using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    class Day_22_Binary_Search_Trees
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

        class Solution
        {
            static int getHeight(Node root)
            {
                //Write your code here
                if (root == null)
                    return -1;
                int leftDepth = getHeight(root.left);
                int rightDepth = getHeight(root.right);
                return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
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
                int height = getHeight(root);
                Console.WriteLine(height);

            }
        }
    }
}
