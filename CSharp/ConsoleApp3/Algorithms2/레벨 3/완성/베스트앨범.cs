using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace ConsoleApp3.Algorithms2.레벨_3
{
    class 베스트앨범
    {
        struct Item {
            public int index;
            public int play;
        }

    

        public int[] solution(string[] genres, int[] plays)
        {
            List<int> answers = new List<int>();
            Dictionary<string, int> my_dict = new Dictionary<string, int>();

            Dictionary<string, List<Item>> my_dict2 = new Dictionary<string, List<Item>>();

            for (int i = 0; i < genres.Length; i++)
            {
                Item item = new Item();
                item.index = i;
                item.play = plays[i];

                if (my_dict.ContainsKey(genres[i]) == false)
                {
                    my_dict.Add(genres[i], plays[i]);
                    my_dict2.Add(genres[i], new List<Item>() { item });

                }
                else
                {
                    my_dict[genres[i]] += plays[i];
                    my_dict2[genres[i]].Add(item);
                }
            }

            List<string> generList = new List<string>(my_dict.Keys);//TODO 리스트 정렬
            generList.Sort((l, r) =>
            {
                if (my_dict[l] > my_dict[r])
                {
                    return -1;
                }
                else if (my_dict[l] < my_dict[r])
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            });

            for (int i = 0; i < generList.Count; i++)
            {
                string gener = generList[i];
                var list = my_dict2[gener];

                list.Sort((l, r) =>
                {
                    if (l.play > r.play)
                        return -1;
                    else if (l.play < r.play)
                        return 1;
                    else
                        return 0;
                });

                answers.Add(list[0].index);

                if (list.Count >= 2)
                {
                    answers.Add(list[1].index);
                }
            }

            return answers.ToArray();
        }

        public int[] solution1(string[] genres, int[] plays)
        {
            Dictionary<string, List<Item>> dicPlay = new Dictionary<string, List<Item>>();
            Dictionary<string, int> dicIndex = new Dictionary<string, int> ();
            for (int i = 0; i < genres.Length; i++)
            {
                Item item = new Item();
                item.index = i;
                item.play = plays[i];

                if (dicPlay.ContainsKey(genres[i]))
                {
                    dicPlay[genres[i]].Add(item);
                    dicIndex[genres[i]]+=plays[i];
                }
                else
                {
                    dicPlay.Add(genres[i], new List<Item>() { item });
                    dicIndex.Add(genres[i], plays[i]);
                }
            }
            

            for (int i = 0; i < dicPlay.Count; i++)
            {
                var item = dicPlay.Keys.ToArray();
                dicPlay[item[i]] = dicPlay[item[i]].OrderBy(x => x.play).ThenByDescending(s => s.index).ToList();
            }

            List<int> answer = new List<int>();

            foreach (var item in dicIndex.OrderByDescending(key => key.Value))
            {
                if (dicPlay[item.Key].Count == 1)
                {
                    answer.Add(dicPlay[item.Key][0].index);
                }
                else
                {
                    answer.Add(dicPlay[item.Key][dicPlay[item.Key].Count - 1].index);
                    answer.Add(dicPlay[item.Key][dicPlay[item.Key].Count - 2].index);
                }
            }


            return answer.ToArray();
        }
    }
}
