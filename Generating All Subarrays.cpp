#include <iostream>
#include <vector>
using namespace std;

// Recursive function to print all possible subarrays for given array
void printSubArraysRec(vector<int> &arr, int start, int end)
{

    // Stop if we have reached the end of the array
    if (end == arr.size())
        return;

    // Increment the end point and reset the start to 0
    else if (start > end)
        printSubArraysRec(arr, 0, end + 1);

    // Print the subarray and increment the starting point
    else
    {
        for (int i = start; i <= end; i++)
            cout << arr[i] << " ";
        cout << endl;
        printSubArraysRec(arr, start + 1, end);
    }
}

// Prints all subarrays in arr[0..n-1]
void subArrayIter(vector<int> &arr)
{
    int n = arr.size();

    // Pick starting point
    for (int i = 0; i < n; i++)
    {
        // Pick ending poin
        for (int j = i; j < n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << endl;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << "All Non-empty Subarrays\n";
    subArrayIter(arr);

    cout << endl;
    printSubArraysRec(arr, 0, 0);
    return 0;
}