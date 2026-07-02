// 2026/07/02 20:17:40
// https://www.geeksforgeeks.org/dsa/count-set-bits-of-number-using-recursion/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int countSetBits(int n)
{
    if (n == 0)
        return 0;

    return (n & 1) + countSetBits(n >> 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 20;
    cout << countSetBits(n);

    n = 21;
    cout << countSetBits(n);

    n = 16;
    cout << countSetBits(n);
    return 0;
}