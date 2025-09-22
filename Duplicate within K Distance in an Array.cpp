#include <bits/stdc++.h>
using namespace std;

// C++ program to Check if a given array contains duplicate
// elements within k distance from each other
bool checkDuplicatesWithinK(vector<int> &arr, int k)
{
    // Creates an empty hashset
    unordered_set<int> s;

    // Traverse the input array
    for (int i = 0; i < arr.size(); i++)
    {

        // If already present in hash, then we found
        // a duplicate within k distance
        if (s.find(arr[i]) != s.end())
            return true;

        // Add this item to hashset
        s.insert(arr[i]);

        // Remove the k+1 distant item
        if (i >= k)
            s.erase(arr[i - k]);
    }
    return false;
}

bool checkDuplicatesWithinK_naive(vector<int> &arr, int k)
{
    int n = arr.size();

    // Traverse for every element
    for (int i = 0; i < n; i++)
    {

        // Traverse next k elements
        for (int c = 1; c <= k && (i + c) < n; c++)
        {
            int j = i + c;

            // If we find one more occurrence
            // within k
            if (arr[i] == arr[j])
                return true;
        }
    }
    return false;
}

// Driver method to test above method
int main()
{
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    checkDuplicatesWithinK_naive(arr, 3) ? cout << "Yes" : cout << "No";

    cout << endl;
    checkDuplicatesWithinK(arr, 3) ? cout << "YES" : cout << "NO";
    return 0;
}