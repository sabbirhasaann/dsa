#include <bits/stdc++.h>
using namespace std;

bool isEven(int n)
{
    if(n%2)
        return false;
    else
        return true;
}

bool isEvenEfficient(int n)
{   
    if ((n & 1) == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    cout << isEven(n) << endl;
    cout << isEvenEfficient(n) << endl;
}