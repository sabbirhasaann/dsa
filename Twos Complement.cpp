// 2026/02/23 12:04:21
// https://www.geeksforgeeks.org/dsa/twos-complement/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

unsigned int twosComplement(int n){
    return ~n + 1;
}

int main(){
    ios_base::sync_with_stdio(false);

    cout << bitset<32>(twosComplement(1)) << endl;
    // cout << twosComplement(-1);
    cout << bitset<32>(-1) << endl;
    // cout << bitset<33>(INT_MAX) << endl;

    return 0;
}