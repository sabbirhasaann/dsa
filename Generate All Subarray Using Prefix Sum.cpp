#include <iostream>
#include <vector>

void generateSubarraysWithPrefixSum(const std::vector<int> &arr)
{
    int n = arr.size();

    // 1. Generate the prefix sum array
    std::vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    // 2. Generate all subarrays and use the prefix sum to calculate their sum
    std::cout << "Subarrays and their sums:" << std::endl;
    for (int start = 0; start < n; ++start)
    {
        for (int end = start; end < n; ++end)
        {
            // The subarray runs from index 'start' to 'end' (inclusive)

            // Calculate the sum using the prefix sum array in O(1) time:
            // Sum of arr[start...end] = prefixSum[end + 1] - prefixSum[start]
            int subarraySum = prefixSum[end + 1] - prefixSum[start];

            // Print the subarray elements
            std::cout << "[";
            for (int k = start; k <= end; ++k)
            {
                std::cout << arr[k] << (k == end ? "" : ", ");
            }
            std::cout << "] Sum: " << subarraySum << std::endl;
        }
    }
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4};
    generateSubarraysWithPrefixSum(arr);
    return 0;
}
