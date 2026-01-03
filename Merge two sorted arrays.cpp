// 2025/12/10 07:01:47

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<int> naive_merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> merged;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            merged.push_back(nums1[i]);
            i++;
        }
        else
        {
            merged.push_back(nums2[j]);
            j++;
        }
    }
    while (i < m)
    {
        merged.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        merged.push_back(nums2[j]);
        j++;
    }
    return merged;
}
void printArray(vector<int> v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
void soln()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    printArray(naive_merge(nums1, m, nums2, n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}