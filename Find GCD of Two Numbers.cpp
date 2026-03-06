#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int gcdRec(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int gcdOps(int a, int b)
{
    if (b == 0)
        return 0;
    return a/b + gcd(b, a % b);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    cout << gcdRec(a, b) << endl;
    cout << gcdOps(max(a,b), min(a,b)) << endl;
}