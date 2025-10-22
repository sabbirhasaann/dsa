// Maximum Sum of a Subarray with K Elements

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int maxSum(vector<int> &arr, int k)
{
    int n = arr.size();

    // n must be greater
    if (n <= k)
    {
        cout << "Invalid";
        return -1;
    }

    // Compute sum of first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += arr[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int window_sum = max_sum;
    for (int i = k; i < n; i++)
    {
        window_sum += arr[i] - arr[i - k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int maxSum_naive(vector<int> &arr, int k)
{
    int n = arr.size();
    int max_sum = INT_MIN;

    // Consider all blocks starting with i
    for (int i = 0; i <= n - k; i++)
    {
        int current_sum = 0;

        // Calculate sum of current subarray of size k
        for (int j = 0; j < k; j++)
            current_sum += arr[i + j];

        // Update result if required
        max_sum = max(current_sum, max_sum);
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {5, 2, -1, 0, 3};
    int k = 3;

    cout << maxSum_naive(arr, k) << endl;
    cout << maxSum(arr, k) << endl;
    return 0;
}