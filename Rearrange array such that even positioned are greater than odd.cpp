// C++ program to Rearrange array such that even positioned are greater than odd

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArraySwap(vector<int> &arr)
{
    int n = arr.size();

    vector<int> result(n);

    // Traverse the array and make adjustments to satisfy the condition
    for (int i = 1; i < n; i++)
    {

        // Check if the index is even (1-based), i.e., i+1 is even
        if ((i + 1) % 2 == 0)
        {

            // Ensure that the current element is greater than or
            // equal to the previous element
            if (arr[i] < arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
        else
        {
            // Ensure that the current element is less than or equal
            // to the previous element
            if (arr[i] > arr[i - 1])
                swap(arr[i], arr[i - 1]);
        }
    }
    // Copy the rearranged array into the result array
    for (int i = 0; i < n; i++)
        result[i] = arr[i];

    return result;
}

vector<int> rearrangeArray(vector<int> &arr)
{

    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> ans(n);
    int ptr1 = 0, ptr2 = n - 1;
    for (int i = 0; i < n; i++)
    {

        // Assign even indexes with maximum elements
        if ((i + 1) % 2 == 0)
            ans[i] = arr[ptr2--];

        // Assign odd indexes with remaining elements
        else
            ans[i] = arr[ptr1++];
    }

    return ans;
}

void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1};
    printArray(rearrangeArray(arr));

    printArray(rearrangeArraySwap(arr));
    return 0;
}