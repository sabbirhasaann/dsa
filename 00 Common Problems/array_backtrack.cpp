#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void recurPermuation(int index, vector<int> &arr, vector<vector<int>> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        recurPermuation(index + 1, arr, ans);
        swap(arr[index], arr[i]);
    }
}

vector<vector<int>> findPermutation(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    recurPermuation(0, arr, ans);

    return ans;
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
    vector<vector<int>> ans = findPermutation(arr);

    for (auto i : ans)
    {
        for (auto x : i)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}