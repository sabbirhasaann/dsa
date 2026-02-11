// 2026/02/11 08:58:38
// https://www.geeksforgeeks.org/dsa/nth-term-of-ap-from-first-two-terms/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int nthTermOfAPNaive(int a1, int a2, int n)
{
    int nthTerm = a1, d = a2 - a1;

    for (int i = 1; i < n; i++){
        nthTerm += d;
    }
    return nthTerm;
}

int nthTermOfAPExpected(int a1, int a2, int n){
    return a1 + (n-1) * (a2 - a1);
}

int main(){
    ios_base::sync_with_stdio(false);
    int a1 = 2;
    int a2 = 3;
    int n = 4;
    cout << nthTermOfAPNaive(a1,a2,n) << endl;
    cout << nthTermOfAPExpected(a1,a2,n) << endl;

    return 0;
}