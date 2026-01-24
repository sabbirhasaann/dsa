#include <bits/stdc++.h>
using namespace std;

long long findSumNaive(int n){
    long long sum = 0;
    for(int i=1;i<=n;i++)
        sum += i;
    return sum;
}

long long findSumRec(int n){
    if(n == 1)
        return 1;
    return n + findSumRec(--n);
}

long long findSumExpected(int n){
    return n * (n + 1) / 2;
}


int main()
{
    int n;
    cin >> n;
    cout << findSumNaive(n) << endl;
    cout << findSumRec(n) << endl;
    cout << findSumExpected(n)<< endl;
}