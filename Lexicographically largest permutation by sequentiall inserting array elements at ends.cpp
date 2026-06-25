// 2026/06/25 07:38:41
// https://www.geeksforgeeks.org/dsa/lexicographically-largest-permutation-by-sequentiall-inserting-array-elements-at-ends/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void largestPermutation(vector<int> &a)
{
    deque<int> dq;

    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] >= dq.front())
            dq.push_front(a[i]);

        else
            dq.push_back(a[i]);
    }

    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> arr = {3, 1, 2, 4};
    largestPermutation(arr);

    arr = {1, 2, 3, 4, 5};
    largestPermutation(arr);

    return 0;
}