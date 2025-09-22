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

int factorial_iter(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        // calculating the factorial
        ans = ans * i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    cout << factorial(n) << endl;
    cout << factorial_iter(n) << endl;
}