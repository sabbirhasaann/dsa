// 2026/03/17 01:37:11
// https://www.geeksforgeeks.org/dsa/program-for-factorial-of-a-number/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

long long factorial(long long n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int factorial_iter(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans = ans * i;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n=5;
    cout << factorial(n) << endl;

    n = 4;
    cout << factorial(n) << endl;

    // cin >> n;

    return 0;
}


// Input: n = 5
// Output: 120
// Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120

// Input: n = 4
// Output: 24
// Explanation: 4! = 4 * 3 * 2 * 1 = 24