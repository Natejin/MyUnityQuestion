using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms2.레벨_3
{


    class 여행경로
    {


        public string[] solution(string[,] tickets)
        {
            string[] answer = new string[] { };
            List<string[]> reformTickets = new List<string[]>();

            for (int i = 0; i < tickets.GetLength(0); i++)
            {
                reformTickets.Add(new string[] { tickets[i, 0], tickets[i, 1] });
            }

            List<string> airPortsList = new List<string>();
            string airports = "ICN";
            FindAirport(airports, "ICN", reformTickets.ToArray(), ref airPortsList);

            airPortsList.Sort();
            answer = airPortsList.First().Split(',');

            return answer;
        }

        private void FindAirport(string airports, string lastAirPort, string[][] remainTickets, ref List<string> airportsList)
        {
            foreach (string[] item in remainTickets.Where(s => s[0] == lastAirPort))
            {
                string tempAirports = string.Format("{0},{1}", airports, item[1]);
                if (remainTickets.Count() == 1)
                {
                    airportsList.Add(tempAirports);
                    return;
                }
                List<string[]> tempTickets = remainTickets.ToList();
                tempTickets.Remove(item);
                FindAirport(tempAirports, item[1], tempTickets.ToArray(),ref airportsList);
            }
        }
    }
}
