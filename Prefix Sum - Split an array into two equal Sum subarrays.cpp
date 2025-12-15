#include <bits/stdc++.h>
using namespace std;
int findSplitPoint(vector<int> &arr)
{
    int prefS = 0, total = 0;
    total = accumulate(arr.begin(), arr.end(), total);

    for (int pivot = 0; pivot < arr.size(); pivot++)
    {
        int suffS = total - prefS - arr[pivot];
        prefS += arr[pivot];
        if (prefS == suffS)
            return pivot;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 5};
    int idx = findSplitPoint(arr);
    for (int i = 0; i <= idx; i++)
        cout << arr[i] <<" ";
    cout << endl;
    for (int i = idx + 1; i < arr.size(); i++)
        cout << arr[i] << " ";
}