#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void print(vector<int> &arr, int i)
{
    if (i == 0)
        return;
    print(arr, i - 1);
    cout << arr[i - 1] << " ";
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

    print(arr, n);
}