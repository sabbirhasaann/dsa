// 2026/05/22 15:36:39
// https://www.geeksforgeeks.org/dsa/minimize-the-maximum-difference-between-adjacent-elements-in-an-array/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int minDifference(vector<int> &arr, int k)
{
    int n = arr.size();
    int minDiff = INT_MAX;
    for (int i = 1; i < (1 << n); i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                v.push_back(arr[j]);
        }
        if (v.size() == n - k)
        {
            int maxDiff = INT_MIN;
            for (int j = 1; j < v.size(); ++j)
            {
                int d = v[j] - v[j - 1];
                maxDiff = max(maxDiff, d);
            }
            minDiff = min(minDiff, maxDiff);
        }
        v.clear();
    }
    return minDiff;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> a = {3, 7, 8, 10, 14};
    int k = 2;
    cout << minDifference(a, k) << endl;

    a = {12, 16, 22, 31, 31, 38};
    k = 3;
    cout << minDifference(a, k) << endl;

    return 0;
}