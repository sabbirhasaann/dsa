// 2025/10/26 01:20:01

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void sort_ott(vector<int> &arr)
{
    vector<int> freq(3, 0);
    for (int x : arr)
        freq[x]++;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i < freq[0])
            arr[i] = 0;
        else if (i >= freq[0] && i < (freq[0] + freq[1]))
            arr[i] = 1;
        else if (i >= freq[0] + freq[1])
            arr[i] = 2;
    }
}

void soln()
{
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    sort_ott(arr);
    printArray(arr);

    arr = {2, 0, 1};
    sort_ott(arr);
    printArray(arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}