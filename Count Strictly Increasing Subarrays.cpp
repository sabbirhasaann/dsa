#include <bits/stdc++.h>
using namespace std;

// C++ Code to count strictly increasing
// subarrays using Length based Formula
// Function to count strictly increasing
// subarrays
int countIncreasing_expected(vector<int> &arr)
{

    int n = arr.size();
    int count = 0;
    int len = 1;

    // Iterate through the array
    for (int i = 1; i < n; i++)
    {

        // If current element is greater than
        // previous, increase len
        if (arr[i] > arr[i - 1])
        {
            len++;
        }

        else
        {

            // Add subarrays count and reset len
            count += (len * (len - 1)) / 2;
            len = 1;
        }
    }

    // Add remaining subarrays count
    count += (len * (len - 1)) / 2;

    return count;
}

// C++ Code to count strictly increasing
// subarrays using Better Approach
// Function to count strictly increasing
// subarrays
int countIncreasing_better(vector<int> &arr)
{

    int n = arr.size();
    int count = 0;

    // Iterate over all possible subarrays
    for (int i = 0; i < n; i++)
    {

        // Start from index i
        for (int j = i + 1; j < n; j++)
        {

            // If the sequence breaks, stop early
            if (arr[j - 1] >= arr[j])
            {
                break;
            }

            // Otherwise, count the valid subarray
            count++;
        }
    }

    return count;
}

// C++ Code to count strictly increasing
// subarrays using Naive Approach
// Function to count strictly increasing
// subarrays
int countIncreasing_naive(vector<int> &arr)
{

    int n = arr.size();
    int count = 0;

    // Iterate over all possible subarrays
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // Check if the current subarray is
            // strictly increasing
            bool isIncreasing = true;
            for (int k = i; k < j; k++)
            {
                if (arr[k] >= arr[k + 1])
                {
                    isIncreasing = false;
                    break;
                }
            }

            // If strictly increasing,
            // increment count
            if (isIncreasing)
            {
                count++;
            }
        }
    }

    return count;
}

// Driver code
int main()
{

    vector<int> arr = {1, 4, 5, 3, 7, 9};

    cout << countIncreasing_naive(arr) << endl;
    cout << countIncreasing_better(arr) << endl;
    cout << countIncreasing_expected(arr) << endl;
    return 0;
}