// 2025/09/02 20:26:18

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxSubarraySum(vector<int> &arr)
{
    int maxSoFar = INT_MIN, maxEndingHere = 0;
    int start, end, s;
    start = end = s = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxEndingHere += arr[i];
        if (maxSoFar < maxEndingHere)
        {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }
        if (maxEndingHere < 0)
        {
            maxEndingHere = 0;
            s = i + 1;
        }
    }
    cout << start << " " << end << endl;
    return maxSoFar;
}
void soln()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSubarraySum(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}