// 2026/05/14 11:07:08
// https://www.geeksforgeeks.org/dsa/basic-operations-for-queue-in-data-structure/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);

    queue<int> q;
    q.push(10);

    cout << q.back() << endl;
    cout << q.front() << endl;

    if (q.empty())
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;

    cout << q.size() << endl;
    return 0;
}