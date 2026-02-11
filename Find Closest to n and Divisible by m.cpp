// 2026/02/11 08:18:49
// https://www.geeksforgeeks.org/dsa/find-closest-to-n-and-divisible-by-m/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int closestNumberNaive(int n,int m){
    int closest = 0;
    int minDifference = INT_MAX;

    // Check numbers around n
    for (int i = n - abs(m); i <= n + abs(m); ++i) {
        if (i % m == 0) {
            int difference = abs(n - i);

            if (difference < minDifference || 
               (difference == minDifference && abs(i) > abs(closest))) {
                closest = i;
                minDifference = difference;
            }
        }
    }
    return closest;
}

int closestNumberExpected(int n,int m){
    int q = n / m;

    // 1st possible closest number
    int n1 = q * m;

    // 2nd possible closest number
    int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1));

    if(abs(n-n1) < abs(n-n2))
        return n1;
    return n2;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n = 13, m = 4;
    cout << closestNumberNaive(n,m) << endl;

    n = 13, m = 4;
    cout << closestNumberExpected(n,m) << endl;

    return 0;
}