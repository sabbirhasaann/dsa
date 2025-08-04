#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void rev(string &s, int i, int j)
{
    if (i > j)
        return;
    rev(s, i + 1, j - 1);
    swap(s[i], s[j]);
    `
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    rev(s, 0, s.size() - 1);
    cout << s;
}