// 2025/12/16 07:39:32

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> decodePresumArray(vector<int> &presum)
{
    int n = presum.size();
    vector<int> arr(n);
    arr[0] = presum[0];
    for (int i = 1; i < n; i++)
        arr[i] = presum[i] - presum[i - 1];
    return arr;
}
void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> presum = {5, 7, 10, 11, 18}, res;
    res = decodePresumArray(presum);
    printArray(res);

    presum = {45, 57, 63, 78, 89, 97};
    res = decodePresumArray(presum);
    printArray(res);

    return 0;
}