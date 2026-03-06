// 2026/03/07 02:19:59
// https://www.geeksforgeeks.org/dsa/1d-difference-array/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


// Apply a single range update on the difference array
void update(vector<int>& diff, int l, int r, int x) {
    diff[l] += x;
    if (r + 1 < diff.size()) {
        diff[r + 1] -= x;
    }
}

// Apply range updates using difference array technique
vector<int> diffArray(vector<int>& arr, vector<vector<int>>& opr) {
    int n = arr.size();

    // Create difference array 
    vector<int> diff(n, 0);

    // Apply each operation [l, r, val] on the diff array
    for (auto& q : opr) {
        int l = q[0], r = q[1], val = q[2];
        update(diff, l, r, val);
    }

    // Build the result by applying prefix sum over diff
    vector<int> res = arr;
    res[0] += diff[0];
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1]; 
        res[i] += diff[i];      
    }

    return res;
}

// In-Place Implementation (Without Extra Space)

vector<int> diffArrayInPlace(vector<int>& arr, vector<vector<int>>& opr) {
    int n = arr.size();

    // Convert arr to in-place difference array
    for (int i = n - 1; i > 0; i--) {
        arr[i] -= arr[i - 1];
    }

    // Apply each operation directly on the original array
    // Each operation is of the form [l, r, v]
    for (auto& q : opr) {
        int l = q[0], r = q[1], v = q[2];

        // Adding v at index l
        arr[l] += v;

        // Subtracting v at index r + 1 ensures the addition 
        // stops at index r when prefix sums are applied
        if (r + 1 < n) arr[r + 1] -= v;
    }

    // Take prefix sum to get the final updated array
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    return arr;
}

int main(){
    ios_base::sync_with_stdio(false);

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> opr = {
        {1, 3, 10}, {2, 4, -5}
    };

    vector<int> res = diffArray(arr, opr);

    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    res = diffArrayInPlace(arr, opr);

    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}