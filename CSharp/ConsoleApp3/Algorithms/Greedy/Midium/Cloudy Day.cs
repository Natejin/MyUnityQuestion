using NateJin;
using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApp3.Algorithms.Greedy.Midium
{
    class Cloudy_Day
    {
        class city : IComparable<city>
        {
            public long location;
            public cloudy clouds;
            public long pop;

            public city(long location, long pop)
            {
                this.location = location;
                this.pop = pop;
            }

            public int CompareTo([AllowNull] city other)
            {
                return location.CompareTo(other.location);
            }

            public static bool operator >(city lhs, long rhs)
            {
                if (lhs.location > rhs) return true;
                return false;
            }

            public static bool operator <(city lhs, long rhs)
            {
                if (lhs.location < rhs) return true;
                return false;
            }

            public static bool operator >=(city lhs, long rhs)
            {
                if (lhs.location >= rhs) return true;
                return false;
            }

            public static bool operator <=(city lhs, long rhs)
            {
                if (lhs.location <= rhs) return true;
                return false;
            }
        }

        class cloudy {
            public long start;
            public long end;
            public List<city> underCloudyCity = new List<city>();

            public cloudy(long loc, long range)
            {

                this.start = loc - range < 0 ? 0 : loc - range;
                this.end = loc + range;
            }

            public void addCity(city city) {
                underCloudyCity.Add(city);
            }
        }

        static long maximumPeople(long[] p, long[] x, long[] y, long[] r)
        {
            List<cloudy> cloudy = new List<cloudy>();
            SortedList<long, city> citySorted = new SortedList<long, city>();
            int i = 0;
            for ( i = 0; i < x.Length; i++)
            {
                if (citySorted.ContainsKey(x[i]))
                {
                    citySorted[x[i]].pop += p[i];
                }
                else {
                    citySorted.Add(x[i], new city(x[i], p[i]));
                }
            }

            var keyList = citySorted.Keys.ToList();
            var alwaysUnderCloudy = new List<long>();
            i = 0;
            while (i < y.Length)
            {
                Console.WriteLine("cityremain {0}", keyList.Count);
                cloudy.Add(new cloudy(y[i], r[i]));

                int startCityIndex = keyList.BinarySearch(cloudy[i].start);
                int endCityIndex = keyList.BinarySearch(cloudy[i].end);
                startCityIndex = startCityIndex < 0 ? -startCityIndex - 1 : startCityIndex;
                endCityIndex = endCityIndex < 0 ? -endCityIndex - 2 : endCityIndex;
                Console.WriteLine("startindex {0} endindex {1} cloudystart {2} cloudyend {3}", startCityIndex, endCityIndex, cloudy[i].start, cloudy[i].end);
                for (int j = startCityIndex; j <= endCityIndex; j++)
                {

                    Console.WriteLine("cloudy[{0}] cityindex[{0}]", i, j);
                    if (citySorted[keyList[j]].clouds == null)
                    {
                        citySorted[keyList[j]].clouds = cloudy[i];
                        cloudy[i].addCity(citySorted[keyList[j]]);
                    }
                    else
                    {
                        alwaysUnderCloudy.Add(keyList[j]);
                    }
                }

                for (int j = 0; j < alwaysUnderCloudy.Count; j++)
                {
                    Console.WriteLine("Remove {0}", alwaysUnderCloudy[j]);
                    citySorted[alwaysUnderCloudy[j]].clouds.underCloudyCity.Remove(citySorted[alwaysUnderCloudy[j]]);
                    citySorted[alwaysUnderCloudy[j]].clouds = null;
                    keyList.Remove(alwaysUnderCloudy[j]);
                }
                alwaysUnderCloudy.Clear();
                i++;
            }
        

            long sunnyppl = 0;
            foreach (var item in keyList)
            {
                if (citySorted[item].clouds != null)
                {
                    sunnyppl += citySorted[item].pop;
                }
            }

            long max = 0;
            foreach (var item in cloudy)
            {
                long numOfSunnypeopleWhenRemoveThisCloud = 0;
                for ( i = 0; i < item.underCloudyCity.Count; i++)
                {
                    numOfSunnypeopleWhenRemoveThisCloud += item.underCloudyCity[i].pop;
                }
                max = Math.Max(numOfSunnypeopleWhenRemoveThisCloud, max);
            }

            return max + sunnyppl;
        }

        static void Main(string[] args)
        {
            TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

            int n = Convert.ToInt32(Console.ReadLine());

            long[] p = Array.ConvertAll(Console.ReadLine().Split(' '), pTemp => Convert.ToInt64(pTemp))
            ;

            long[] x = Array.ConvertAll(Console.ReadLine().Split(' '), xTemp => Convert.ToInt64(xTemp))
            ;
            int m = Convert.ToInt32(Console.ReadLine());

            long[] y = Array.ConvertAll(Console.ReadLine().Split(' '), yTemp => Convert.ToInt64(yTemp))
            ;

            long[] r = Array.ConvertAll(Console.ReadLine().Split(' '), rTemp => Convert.ToInt64(rTemp))
            ;
            long result = maximumPeople(p, x, y, r);

            textWriter.WriteLine(result);

            textWriter.Flush();
            textWriter.Close();
        }
    }
}
