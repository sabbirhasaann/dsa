#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << sum(n);
}