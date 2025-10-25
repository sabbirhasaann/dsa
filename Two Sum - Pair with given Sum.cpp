#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;



bool twoSum_expected(vector<int> &arr, int target){

    // Create an unordered_set to store the elements
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++){

        // Calculate the complement that added to
        // arr[i], equals the target
        int complement = target - arr[i];

        // Check if the complement exists in the set
        if (s.find(complement) != s.end())
            return true;

        // Add the current element to the set
        s.insert(arr[i]);
    }

    // If no pair is found
    return false;
}

bool twoSum_better2(vector<int> &arr, int target){

    sort(arr.begin(), arr.end());

    int left = 0, right = arr.size() - 1;

    // Iterate while left pointer
    // is less than right
    while (left < right){
        int sum = arr[left] + arr[right];

        // Check if the sum matches the target
        if (sum == target)
            return true;
        else if (sum < target)

        // Move left pointer to the right
            left++;
        else

        // Move right pointer to the left
            right--;
    }
    // If no pair is found
    return false;
}


// Function to perform binary search
bool binarySearch(vector<int> &arr, int left,
                          int right, int target){
    while (left <= right){
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

bool twoSum_better1(vector<int> &arr, int target){

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];

        // Use binary search to
        // find the complement
        if (binarySearch(arr, i + 1,
                    arr.size() - 1, complement))
            return true;
    }

    // If no pair is found
    return false;
}

bool twoSum_naive(vector<int> &arr, int target)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        // For each element arr[i], check every
        // other element arr[j] that comes after it
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

    // If no pair is found after checking
    // all possibilities
    return false;
}

int main()
{

    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    twoSum_naive(arr, target) ? cout << "true\n" : cout << "false\n";
    twoSum_better1(arr, target) ? cout <<"True\n" : cout << "False\n";
    twoSum_better2(arr, target) ? cout << "TRUE\n" : cout << "FALSE\n";
    twoSum_expected(arr, target) ? cout << "TruE\n" : cout <<"FalsE\n";
    return 0;
}