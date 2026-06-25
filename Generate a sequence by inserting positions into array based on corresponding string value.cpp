// 2026/06/25 07:20:57
// https://www.geeksforgeeks.org/dsa/generate-a-sequence-by-inserting-positions-into-array-based-on-corresponding-string-value/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void findSequence(string s)
{
    int n = s.length();
    deque<int> dq;
    dq.push_back(n);

    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'F')
            dq.push_back(i);
        else
            dq.push_front(i);
    }
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s = "FBBFB";
    findSequence(s);

    s = "BBBBBB";
    findSequence(s);

    return 0;
}