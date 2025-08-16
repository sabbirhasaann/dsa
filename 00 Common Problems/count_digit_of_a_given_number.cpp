#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int count_digit(int n)
{
    if (n == 0 || n < 10)
        return 1;
    return 1 + count_digit(n / 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cout << count_digit(n);
}