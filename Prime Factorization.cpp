// 2025/09/12 18:52:37

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> factorUpToSqrtn(int n)
{
    vector<int> ret;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        ret.push_back(n);
    }
    return ret;
}

vector<int> factor(int n)
{
    vector<int> ret;
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            ret.push_back(i);
            n /= i;
        }
    }
    return ret;
}
void printVec(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    int n;
    cin >> n;
    vector<int> factors = factor(n);
    printVec(factors);

    vector<int> factors2 = factorUpToSqrtn(n);
    printVec(factors2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}