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


vector<long long> primeFactors(long long n) {
    vector<long long> factors;

    // Divide by 2 repeatedly until n is odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for odd factors from 3 up to sqrt(n)
    // We increment by 2 to skip even numbers
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2 at this point, add it
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
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