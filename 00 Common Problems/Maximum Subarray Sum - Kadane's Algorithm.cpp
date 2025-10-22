// 2025/09/02 20:26:18

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int maxSubarraySumIndex(vector<int> &arr)
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

int maxSubarraySum(vector<int> &arr)
{

    // Stores the result (maximum sum found so far)
    int res = arr[0];

    // Maximum sum of subarray ending at current position
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {

        // Either extend the previous subarray or start
        // new from current element
        maxEnding = max(arr[i], maxEnding + arr[i]);

        // Update result if the new subarray sum is larger
        res = max(res, maxEnding);
    }
    return res;
}

int maxSubarraySumNaive(vector<int> &arr)
{
    int res = arr[0];

    // Outer loop for starting point of subarray
    for (int i = 0; i < arr.size(); i++)
    {
        int currSum = 0;

        // Inner loop for ending point of subarray
        for (int j = i; j < arr.size(); j++)
        {
            currSum = currSum + arr[j];

            // Update res if currSum is greater than res
            res = max(res, currSum);
        }
    }
    return res;
}
void soln()
{
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySumNaive(arr) << endl;
    cout << maxSubarraySumIndex(arr) << endl;
    cout << maxSubarraySum(arr) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}