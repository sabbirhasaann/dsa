// 2026/03/10 07:47:50
// https://www.geeksforgeeks.org/dsa/sum-of-array-elements-using-recursion/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int RecSum(vector<int> &a, int n){
    if(n==0)
        return a[0];
    return a[n-1] + RecSum(a,n-1);
}


int main(){
    ios_base::sync_with_stdio(false);

    vector<int> a = {1, 2, 3};
    int n = a.size();
    cout << RecSum(a,n) << endl;

    return 0;
}