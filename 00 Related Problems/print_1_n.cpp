#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void solve(int n)
{
    if (n == 0)
        return;

    solve(n - 1);
    cout << n << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = 50;
    // cin >> n;

    solve(n);
}