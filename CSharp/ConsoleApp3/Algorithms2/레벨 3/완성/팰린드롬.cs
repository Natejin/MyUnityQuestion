using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    //문제 설명
    //  앞뒤를 뒤집어도 똑같은 문자열을 팰린드롬(palindrome)이라고 합니다.
    //  문자열 s가 주어질 때, s의 부분문자열(Substring) 중 가장 긴 팰린드롬의 길이를 return 하는 solution 함수를 완성해 주세요.
    //
    //예를들면, 문자열 s가 abcdcba이면 7을 return하고 abacde이면 3을 return합니다.
    //
    //제한사항
    //  문자열 s의 길이 : 2,500 이하의 자연수
    //  문자열 s는 알파벳 소문자로만 구성




    class 팰린드롬
    {
        public int solution(string s)
        {
            int T = 1;
            int limit = s.Length - 1;
            Stack<char> stack = new Stack<char>();
            char[] charArr = s.ToCharArray();
            stack.Push(charArr[0]);
            int max = 0;
            int count = 1;
            while (T++ < limit)
            {
                if (charArr[T + 1] != stack.Peek())
                {
                    stack.Push(charArr[T]);
                    count++;
                }
                else {
                    count++;
                    while (++T < limit)
                    {
                        if (stack.Peek() == charArr[T])
                        {
                            stack.Pop();
                            count++;
                            if (stack.Count == 0)
                            {
                                break;

                            }
                        }
                        else {
                            break;
                        }
                    }
                    count -= stack.Count;
                    if (max < count)
                    {
                        max = count;
                    }
                    if (T < limit)
                    {
                        stack.Push(charArr[T + 1]);
                        count = 1;
                    }
                    else {
                        break;
                    }
         
                }
            }
            return max;
        }
    }
}
