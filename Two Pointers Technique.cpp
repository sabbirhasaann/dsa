#include <bits/stdc++.h>
using namespace std;

// Function to perform binary search
bool binarySearch(vector<int> &arr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool twoSum3(vector<int> &arr, int target)
{

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];

        // Use binary search to
        // find the complement
        if (binarySearch(arr, i + 1, arr.size() - 1, complement))
            return true;
    }

    // If no pair is found
    return false;
}

bool twoSum2(vector<int> &arr, int target)
{

    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;

        // Move toward a higher sum
        else if (sum < target)
            left++;

        // Move toward a lower sum
        else
            right--;
    }

    // If no pair found
    return false;
}

// Returns number of pairs in arr[0...n-1] with sum
// equal to 'target'
int countPairs(vector<int> &arr, int target)
{
    unordered_map<int, int> freq;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        // Check if the complement (target - arr[i])
        // exists in the map. If yes, increment count
        if (freq.find(target - arr[i]) != freq.end())
        {
            cnt += freq[target - arr[i]];
        }

        // Increment the frequency of arr[i]
        freq[arr[i]]++;
    }
    return cnt;
}

bool twoSum(vector<int> &arr, int target)
{
    int n = arr.size();

    // Consider all pairs (arr[i], arr[j])
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // Check if the sum of the current pair
            // equals the target
            if (arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }

    // If no pair is found after checking all
    return false;
}

int main()
{
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;
    cout << ((twoSum(arr, target)) ? "true" : "false") << endl;

    vector<int> arr1 = {1, 5, 7, -1, 5};
    int target1 = 6;
    cout << countPairs(arr1, target1) << endl;

    vector<int> arr2 = {-3, -1, 0, 1, 2};
    int target2 = -2;

    if (twoSum2(arr2, target2))
        cout << "true";
    else
        cout << "false";

    cout << endl;

    if (twoSum3(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}