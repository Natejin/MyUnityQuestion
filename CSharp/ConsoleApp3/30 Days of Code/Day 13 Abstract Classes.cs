using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3._30_Days_of_Code
{
    public class Day_13_Abstract_Classes {
        public abstract class Book
        {
            public string title;
            public string author;

            public Book(string title, string author)
            {
                this.title = title;
                this.author = author;
            }

            public virtual void display() { }
        }

        class MyBook : Book
        {
            private int price = 0;
            public MyBook(String title, String author, int price) : base(title, author)
            {
                this.price = price;
            }

            public override void display()
            {
                Console.Write("Title: {0} \nAuthor: {1} \nPrice: {2}", title, author, price);
            }
        }

        class Solution
        {
            static void Main(String[] args)
            {
                String title = Console.ReadLine();
                String author = Console.ReadLine();
                int price = Int32.Parse(Console.ReadLine());
                Book new_novel = new MyBook(title, author, price);
                new_novel.display();
            }
        }
    }
    
}
