#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Built In
bool isSortedBuilt(vector<int> &arr)
{

    // is_sorted() is a built-in method
    if (is_sorted(arr.begin(), arr.end()))
        return true;

    return false;
}

// Iterative Approach

bool isSortedIter(vector<int> &arr)
{

    // Iterate over the array and check if
    // every element is greater than or
    // equal to previous element.
    for (int i = 1; i < arr.size(); i++)
        if (arr[i - 1] > arr[i])
            return false;

    return true;
}

// Helper function that takes array and size, used for recursion
bool isSortedHelperRec(vector<int> &arr, int n)
{
    if (n == 0 || n == 1)
        return true;
    return arr[n - 1] >= arr[n - 2] && isSortedHelperRec(arr, n - 1);
}

// Main function to check if array is sorted, only takes array as input
bool isSortedRec(vector<int> &arr)
{
    return isSortedHelperRec(arr, arr.size());
}

int main()
{
    vector<int> arr = {10, 20, 30, 40, 50};
    cout << (isSortedRec(arr) ? "true\n" : "false\n");

    cout << (isSortedIter(arr) ? "ture\n" : "false\n");

    cout << (isSortedBuilt(arr) ? "ture\n" : "false\n");
    return 0;
}