// 2026/06/25 06:54:58
// https://www.geeksforgeeks.org/dsa/string-after-processing-backspace-characters/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string newString(string s)
{
    deque<char> dq;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '#' && !dq.empty())
            dq.pop_back();
        else
            dq.push_back(s[i]);
    }
    string str;

    // for (char c : dq)
    //     str += c;

    while (!dq.empty())
    {
        str += dq.front();
        dq.pop_front();
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s = "abc#de#f#ghi#jklmn#op#";
    cout << newString(s) << endl;

    s = "##geeks##for##geeks#";
    cout << newString(s) << endl;

    return 0;
}