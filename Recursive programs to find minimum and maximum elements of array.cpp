// 2026/07/02 20:34:22
// https://www.geeksforgeeks.org/dsa/recursive-programs-to-find-minimum-and-maximum-elements-of-array/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

pair<int, int> maxAndMin(vector<int> &a, int i)
{
    if (i == 0)
        return {a[0], a[0]};
    pair<int, int> pres = maxAndMin(a, --i);
    if (a[i] < pres.first)
        pres.first = a[i];
    if (a[i] > pres.second)
        pres.second = a[i];

    return pres;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> a = {1, 4, 3, -5, -4, 8, 6};
    pair<int, int> p = maxAndMin(a, a.size() - 1);
    cout << p.first << " " << p.second << endl;

    a = {12, 3, 15, 7, 9};
    p = maxAndMin(a, a.size() - 1);
    cout << p.first << " " << p.second << endl;
    return 0;
}