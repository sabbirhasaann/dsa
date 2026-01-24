#include <bits/stdc++.h>
using namespace std;

long long summationNaive(int n){
    long long sum = 0;
    for(int i=1;i<=n;i++)
        sum += i*i;
    return sum;
}

long long summationExpected(int n){
    return n * (n + 1) * (2*n + 1) / 6;


    // to avoid overflow 
    // n*(n + 1)*(2 * n + 1) / 6 = (n * (n + 1) / 2) * (2 * n + 1) / 3;
    // return (n * (n + 1) / 2) * (2 * n + 1) / 3;
}

int main()
{
    int n;
    cin >> n;
    cout << summationNaive(n) << endl;
    cout << summationExpected(n) << endl;
}