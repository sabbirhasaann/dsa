// 2025/06/04 13:29:02

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<string> allsplits(string &s)
{
    int n = s.size();
    vector<string> splits;

    for (int i = 0; i < n; i++)
    {
        string first = s.substr(0, i);
        string second = s.substr(i);
        if (i != 0)
        {
            splits.push_back(first);
            splits.push_back(second);
        }
    }

    return splits;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    vector<string> splitted_words = allsplits(s);

    for (auto it = splitted_words.begin(); it != splitted_words.end(); it++)
    {
        cout << *it << endl;
    }
}