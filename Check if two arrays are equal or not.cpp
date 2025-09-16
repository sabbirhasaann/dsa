// C++ program to find given two array
// are equal or not
#include <bits/stdc++.h>
using namespace std;

bool checkEqual_expected(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    if (n != m)
        return false;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(b[i]) == mp.end())
            return false;

        if (mp[b[i]] == 0)
            return false;

        mp[b[i]]--;
    }
    return true;
}

bool checkEqual_naive(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();

    // If lengths of array are not equal means
    // array are not equal
    if (n != m)
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return false;

    // If all elements were same.
    return true;
}

int main()
{
    vector<int> a = {3, 5, 2, 5, 2};
    vector<int> b = {2, 3, 5, 5, 2};

    if (checkEqual_naive(a, b))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    if (checkEqual_expected(a, b))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}