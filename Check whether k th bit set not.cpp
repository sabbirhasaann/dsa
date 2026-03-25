// 2026/03/25 08:03:17
// https://www.geeksforgeeks.org/dsa/check-whether-k-th-bit-set-not/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool checkKthBit(int n,int k){
    // return (n & (1<<k)); // left shift
    return (n>>k & 1);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n,k;
    // cin >> n >> k;
    n = 7, k = 2;
    checkKthBit(n,k) ? cout << "Set bit\n" : cout <<"Not set bit\n";

    return 0;
}