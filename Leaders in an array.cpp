#include <bits/stdc++.h>
using namespace std;

vector<int> leaders_expected(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();

    // Start with the rightmost element
    int maxRight = arr[n - 1];

    // Rightmost element is always a leader
    res.push_back(maxRight);

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; i--)
    {

        if (arr[i] >= maxRight)
        {
            maxRight = arr[i];
            res.push_back(maxRight);
        }
    }

    // Reverse the result array to maintain
    // original order
    reverse(res.begin(), res.end());

    return res;
}

// Function to find the leaders in an array
vector<int> leaders_naive(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int j;

        // Check elements to the right
        // of the current element
        for (j = i + 1; j < n; j++)
        {

            // If a larger element is found,
            // break the loop
            if (arr[i] < arr[j])
                break;
        }

        // If no larger element was found,
        // the current element is a leader
        if (j == n)
            res.push_back(arr[i]);
    }

    return res;
}
void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> result = leaders_naive(arr), res1;
    printArray(result);

    res1 = leaders_expected(arr);
    printArray(res1);

    return 0;
}
