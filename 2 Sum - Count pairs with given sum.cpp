// 2025/08/05 09:47:53

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int countPairs_naive(vector<int> &arr, int target)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == target)
                cnt++;

    return cnt;
}

int countPairs_better(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int res = 0;
    int n = arr.size();
    int left = 0, right = n - 1;

    while (left < right)
    {

        // If sum is greater
        if (arr[left] + arr[right] < target)
            left++;

        // If sum is lesser
        else if (arr[left] + arr[right] > target)
            right--;

        // If sum is equal
        else
        {

            int cnt1 = 0, cnt2 = 0;
            int ele1 = arr[left], ele2 = arr[right];

            // Count frequency of first element of the pair
            while (left <= right && arr[left] == ele1)
            {
                left++;
                cnt1++;
            }

            // Count frequency of second element of the pair
            while (left <= right and arr[right] == ele2)
            {
                right--;
                cnt2++;
            }

            // If both the elements are same, then count of
            // pairs = the number of ways to choose 2
            // elements among cnt1 elements
            if (ele1 == ele2)
                res += (cnt1 * (cnt1 - 1)) / 2;

            // If the elements are different, then count of
            // pairs = product of the count of both elements
            else
                res += (cnt1 * cnt2);
        }
    }
    return res;
}

int countPairs_expected(vector<int> &arr, int target)
{
    int n = arr.size(), count = 0;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {

        // Check if the complement (target - arr[i])
        // exists in the map. If yes, increment count
        if (freq.find(target - arr[i]) != freq.end())
            count += freq[target - arr[i]];

        // Increment the frequency of arr[i]
        freq[arr[i]]++;
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;

    // int n, target;
    // cin >> n >> target;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    
    cout << "countPairs Expected Approach: ";
    cout << countPairs_expected(arr, target) << endl;

    cout << "countPairs Better Approach: ";
    cout << countPairs_better(arr, target) << endl;

    cout << "countPairs Naive Approach: ";
    cout << countPairs_naive(arr, target) << endl;
    return 0;
}