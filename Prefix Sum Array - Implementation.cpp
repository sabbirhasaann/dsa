// 2026/03/07 02:12:58
// https://www.geeksforgeeks.org/dsa/prefix-sum-array---implementation/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// function to find the prefix sum array
vector<int> prefSum(vector<int> &arr) {
    int n = arr.size();
    
    // to store the prefix sum
    vector<int> prefixSum(n);

    // initialize the first element
    prefixSum[0] = arr[0];

    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    
    return prefixSum;
}

int main(){
    ios_base::sync_with_stdio(false);

    vector<int> arr = {10, 20, 10, 5, 15};
    vector<int> prefixSum = prefSum(arr);
    for(auto i: prefixSum) {
        cout << i << " " ;
    }

    return 0;
}