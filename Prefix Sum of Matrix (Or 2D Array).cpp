// 2026/03/07 02:15:01
// https://www.geeksforgeeks.org/dsa/prefix-sum-of-matrix-(or-2d-array)/

// How to calculate 2d prefix sum
// prefix[i][j] = arr[i][j] + prefix[i-1][j]  + prefix[i][j-1] - prefix[i-1][j-1]


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<vector<int>> prefixSum2D(vector<vector<int>> &arr) {
    
    // number of rows
    int n = arr.size();
    
    // number of columns
    int m = arr[0].size();
    
    vector<vector<int>> prefix(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // Start with original value
            prefix[i][j] = arr[i][j];
            
            // Add value from top cell if it exists
            if (i > 0) {
                prefix[i][j] += prefix[i - 1][j];
            }
            
            // Add value from left cell if it exists
            if (j > 0) {
                prefix[i][j] += prefix[i][j - 1];
            }
            
            // Subtract overlap from top-left diagonal if it exists
            if (i > 0 && j > 0) {
                prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }

    return prefix;
}


// How to Query Submatrix Sums Using Prefix Sum Matrix
// Suppose we want the sum of all elements inside a submatrix from (r1, c1) to (r2, c2), then the result is:
// prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1]

vector<int> prefixSum2DQueries(vector<vector<int>> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    int m = arr[0].size();

    // Construct prefix sum matrix using 0-based indexing
    vector<vector<int>> prefix(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            // Start with original value
            prefix[i][j] = arr[i][j];

            // Add value from top cell if it exists
            if (i > 0)
                prefix[i][j] += prefix[i - 1][j];

            // Add value from left cell if it exists
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];

            // Subtract overlap from top-left diagonal if it exists
            if (i > 0 && j > 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    vector<int> result;

    // Process each query using inclusion-exclusion
    for (auto &q : queries) {
        int r1 = q[0], c1 = q[1];
        int r2 = q[2], c2 = q[3];

        int total = prefix[r2][c2];
        int top = (r1 > 0) ? prefix[r1 - 1][c2] : 0;
        int left = (c1 > 0) ? prefix[r2][c1 - 1] : 0;
        int overlap = (r1 > 0 && c1 > 0) ? prefix[r1 - 1][c1 - 1] : 0;

        int sum = total - top - left + overlap;
        result.push_back(sum);
    }

    return result;
}


int main(){
    ios_base::sync_with_stdio(false);

    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12},
                               {13, 14, 15, 16}};

    vector<vector<int>> prefix = prefixSum2D(arr);

    for (int i = 0; i < prefix.size(); i++) {
        for (int j = 0; j < prefix[0].size(); j++) {
            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    

    // queries
    vector<vector<int>> queries = {
        {1, 1, 2, 2},  
    };

    vector<int> result = prefixSum2DQueries(arr, queries);

    for (int sum : result) {
        cout << sum << " ";
    }

    cout << endl;

    return 0;
}