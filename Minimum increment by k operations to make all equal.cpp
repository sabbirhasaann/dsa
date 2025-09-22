#include <bits/stdc++.h>
using namespace std;

int minOps(vector<int>& arr, int k) {

    int maxVal = *max_element(arr.begin(), arr.end());
    int res = 0;

    for (int x : arr) {

        // check if element can be made equal to max
        // if not, return -1
        if ((maxVal - x) % k != 0)
            return -1;

        // else, update res for required operations
        res += (maxVal - x) / k;
    }

    return res;
}

int main() {
    vector<int> arr = { 21, 33, 9, 45, 63 };
    int k = 6;

    cout << minOps(arr, k);
    return 0;
}