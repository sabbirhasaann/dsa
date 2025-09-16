// C++ implementation to check whether
// two convex polygons have same center

#include <bits/stdc++.h>
using namespace std;

// Function to check whether two convex
// polygons have the same center or not
int check(int n, int m)
{
    if (m % n == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}

// Driver Code
int main()
{
    int n = 5;
    int m = 10;

    check(n, m);
    return 0;
}