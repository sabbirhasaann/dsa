// 2026/03/25 08:19:30
// https://www.geeksforgeeks.org/dsa/program-to-find-whether-a-given-number-is-power-of-2/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isPowerOfTwo(int n){
    
    // return n>0 && (n & (n-1));
    // Check if n is positive and n & ~(n-1) equals n
    return (n > 0) && ((n & (~(n-1))) == n);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    // cin >> n;
    n = 16;
    n = 5;
    isPowerOfTwo(n) ? cout <<"Not power of two\n" : cout <<"Power of two\n";
    

    return 0;
}