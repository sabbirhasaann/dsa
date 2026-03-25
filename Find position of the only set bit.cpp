// 2026/03/25 08:08:43
// https://www.geeksforgeeks.org/dsa/find-position-of-the-only-set-bit/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int findPosition(int n){
    bool setBit = false;
    int pos = 0;
    while(n){
        if(!setBit){
            if(n&1){
                setBit = !setBit;
            }
        }
        else{
            pos = -1;
            break;
        }
        ++pos;
        n>>=1;
    }
    return pos;
}

int findPositionEff(int n) {
    
    // Check if n has exactly one set bit
    if (n == 0 || (n & (n - 1)) != 0) return -1; 
    
    return log2(n) + 1; 
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    // cin >> n;
    n = 2;
    cout << findPosition(n) << endl;

    n = 5;
    cout << findPosition(n) << endl;
    
    return 0;
}