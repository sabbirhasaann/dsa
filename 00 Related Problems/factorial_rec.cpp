#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll factorial(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    cout << factorial(n);
}