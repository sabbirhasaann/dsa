// 2026/02/09 09:41:09
// https://www.geeksforgeeks.org/dsa/find-the-mex-of-given-array/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int mexSort(vector<int> &a){
    int n = a.size(),meX = 0;
    sort(a.begin(), a.end());

    for(int i=0;i<n;i++)
        if(a[i]==meX)
            ++meX;

    return meX;
}

int mexSet(vector<int> &a){
    set<int> m(a.begin(), a.end());
    int meX = 0;

    for(int x: m)
        if(meX == x)
            ++meX;

    return meX;
}


int mexHashArray(vector<int>& arr) {
    int n = arr.size();
    vector<bool> present(n + 1, false);

    for (int x : arr) {
        if (x <= n) {
            present[x] = true;
        }
    }

    for (int i = 0; i <= n; i++) {
        if (!present[i]) return i;
    }
    return n + 1;
}


int findMEXWithSet(const std::vector<int>& arr) {
    // 1. Insert all elements into the HashSet
    std::unordered_set<int> elements(arr.begin(), arr.end());

    // 2. Start from 0 and check existence
    int mex = 0;
    while (elements.find(mex) != elements.end()) {
        mex++;
    }
    return mex;
}


int findMEXWithMap(const std::vector<int>& arr) {
    // 1. Map number to its frequency (count)
    std::unordered_map<int, int> counts;
    for (int x : arr) {
        counts[x]++;
    }

    // 2. Start from 0 and check if the count exists
    int mex = 0;
    while (counts.count(mex) > 0) {
        mex++;
    }
    return mex;
}

int main(){
    ios_base::sync_with_stdio(false);

    vector<int> arr = {1, 0, 2, 4};
    cout << mexSort(arr) << endl;
    cout << mexHashArray(arr) << endl;

    arr = {-1, -5, 0, 4};
    cout << mexSort(arr) << endl;

    cout << mexSet(arr) << endl;


    return 0;
}