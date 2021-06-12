#include "stdc++.h"
#include <string>
#include <algorithm>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

//하드코딩
long repeatedString(string s, long n) {
    long temp = n / s.size();
    long reminder = n % s.size();
    long count = 0;
    long answer = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (reminder == i + 1)
        {
            answer += count;
        }
        if (s[i] == 'a')
        {
            count++;
        }
    }
    return answer + temp * count;
}

//내장된 함수를 사용해서 풀기
long repeatedString1(string s, long n) {
    long temp = n / s.size();
    long countStr = count(s.begin(), s.end(), 'a');
    s.resize(n % s.size());
    long reminder = count(s.begin(), s.end(), 'a'); ;
    return reminder + temp * countStr;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
