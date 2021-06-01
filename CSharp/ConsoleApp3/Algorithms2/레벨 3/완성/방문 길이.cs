using ConsoleApp3._30_Days_of_Code;
using Microsoft.VisualBasic.CompilerServices;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Text;

namespace ConsoleApp3.Algorithms2
{
    //게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다.명령어는 다음과 같습니다.
    //
    //  U: 위쪽으로 한 칸 가기
    //
    //  D: 아래쪽으로 한 칸 가기
    //
    //  R: 오른쪽으로 한 칸 가기
    //
    //  L: 왼쪽으로 한 칸 가기
    //
    //캐릭터는 좌표평면의(0, 0) 위치에서 시작합니다.좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져  있습니다.
    //
    //예를 들어, ULURRDLLU로 명령했다면
    //
    //1번 명령어부터 7번 명령어까지 다음과 같이 움직입니다.
    //8번 명령어부터 9번 명령어까지 다음과 같이 움직입니다.
    //이때, 우리는 게임 캐릭터가 지나간 길 중 캐릭터가 처음 걸어본 길의 길이를 구하려고 합니다.예를 들어 위의 예시에서 게임 캐릭터가 움직인 길이는 9이지만, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다. (8, 9번 명령어에서 움직인 길은 2, 3번 명령어에서 이미 거쳐 간 길입니다)
    //
    //단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.
    //
    //예를 들어, LULLLLLLU로 명령했다면
    //
    //1번 명령어부터 6번 명령어대로 움직인 후, 7, 8번 명령어는 무시합니다.다시 9번 명령어대로 움직입니다.
    //이때 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다.
    //
    //명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.
    //
    //제한사항
    //dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.
    //dirs의 길이는 500 이하의 자연수입니다.
    class 방문_길이
    {
        class Road : IEquatable<Road>
        {
            public int startPosX;
            public int startPosY;
            public int endPosX;
            public int endPosY;

            public Road(position previousPos, position newPos)
            {
                this.startPosX = previousPos.posX;
                this.startPosY = previousPos.posY;
                this.endPosX = newPos.posX;
                this.endPosY = newPos.posY;
            }

            public override bool Equals(Object obj)
            {
                var other = obj as Road;
                if (other == null) return false;

                return Equals(other);
            }

  

            // This is the method that must be implemented to conform to the 
            // IEquatable contract

            public bool Equals(Road other)
            {
                if (other == null)
                {
                    return false;
                }

                if (ReferenceEquals(this, other))
                {
                    return true;
                }

                // You can also use a specific StringComparer instead of EqualityComparer<string>
                // Check out the specific implementations (StringComparer.CurrentCulture, e.a.).
                if (other.startPosX == startPosX && other.startPosY == startPosY && other.endPosX == endPosX && other.endPosY == endPosY)
                {
                    return true;
                }
                // To compare the members array, you could perhaps use the 
                // [SequenceEquals][2] method.  But, be aware that [] {"a", "b"} will not
                // be considerd equal as [] {"b", "a"}

                return false;

            }

            public override int GetHashCode()
            {
                return HashCode.Combine(startPosX, startPosY, endPosX, endPosY);
            }
        }

        class position
        {

            public int posX;
            public int posY;

            public position(int posX, int posY)
            {
                this.posX = posX;
                this.posY = posY;
            }

            public static position operator +(position a, position b) => new position(a.posX + b.posX, a.posY + b.posY);
        }
        public int solution(string dirs)
        {
            Dictionary<Road, int> dic = new Dictionary<Road, int>();
            char[] charArr = dirs.ToCharArray();
            position currentPos = new position(0, 0);
            for (int i = 0; i < dirs.Length && dic.Count < 121; i++)
            {
                position dir;
                switch (dirs[i])
                {
                    case 'U':
                        dir = new position(0, 1);
                        break;
                    case 'D':
                        dir = new position(0, -1);
                        break;
                    case 'R':
                        dir = new position(1, 0);
                        break;
                    default:
                        dir = new position(-1, 0);
                        break;
                }

                position newPos = dir + currentPos;
                if (newPos.posX < 6 && newPos.posY < 6 && newPos.posX > -6 && newPos.posY > -6)
                {
 
                    if (!dic.ContainsKey(new Road( currentPos, newPos)))
                    {
                        dic.Add(new Road(currentPos, newPos), 1);
                        dic.Add(new Road(newPos, currentPos), 1);
                        if (dic.Count >= 242)
                        {
                            return 121;
                        }
                    }
                    currentPos = newPos;
                }
            }
            return dic.Count / 2;
        }
    }
}


public class Solution
{
    public class Pos
    {
        public int x;
        public int y;

        public Pos(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public static Pos operator +(Pos a, Pos b) => new Pos(a.x + b.x, a.y + b.y);
    }

    public class Road : IEquatable<Road>
    {
        public int sx;
        public int sy;
        public int ex;
        public int ey;

        public Road(Pos start, Pos end)
        {
            sx = start.x;
            sy = start.y;
            ex = end.x;
            ey = end.y;
        }

        public bool Equals([AllowNull] Road other)
        {
            if ((other.sx == sx && 
                other.sy == sy &&
                other.ex == ex &&
                other.ey == ey)|| (
                other.sx == ex&&
                other.sy ==ey &&
                other.ex == sx&&
                other.ey == sy))
            {
                return true;
            }
            return false;
        }
    }

    public int solution(string dirs)
    {
        Dictionary<Road, int> dic = new Dictionary<Road, int>();

        char[] target = dirs.ToCharArray();
        Pos curPos = new Pos(0, 0);
        for (int i = 0; i < target.Length; i++)
        {
            Pos newPos;
            switch (target[i])
            {
                case 'U':
                    newPos = curPos + new Pos(0, 1);
                    break;
                case 'L':
                    newPos = curPos + new Pos(1, 0);
                    break;
                case 'R':
                    newPos = curPos + new Pos(-1, 0);
                    break;
                default:
                    newPos = curPos + new Pos(0, -1);
                    break;
            }
            Console.WriteLine("x: {0} y: {1}", newPos.x, newPos.y);
            if (newPos.x > 5 || newPos.y > 5 || newPos.x < -5 || newPos.y < -5)
            {
                continue;
            }
            if (!dic.ContainsKey(new Road(curPos, newPos)))
            {
                dic.Add(new Road(curPos, newPos), 1);
                dic.Add(new Road(newPos, curPos), 1);
            }
            Console.WriteLine(dic.Count);
            curPos = newPos;
        }
        return dic.Count/2;
    }
}