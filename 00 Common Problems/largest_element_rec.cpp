#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int largest(vector<int> &arr, int i, int j)
{
    if (i == j)
        return arr[i];

    int mid = (i + j) / 2;
    int left_mx = largest(arr, i, mid);
    int right_mx = largest(arr, mid + 1, j);

    return max(left_mx, right_mx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << largest(arr, 0, n - 1);
}