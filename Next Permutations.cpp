// 2025/08/19 15:43:08

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void soln()
{
    int n, j, i;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (i = n - 1, j = i - 1; j >= 0 || i >= 0; i--, j--)
        if (arr[j] < arr[i])
            break;

    swap(arr[j], arr[i]);

    for (int k = i, l = n - 1; k <= l; k++, l--)
        swap(arr[k], arr[l]);

    for (int x : arr)
        cout << x << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}