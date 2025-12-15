#include <bits/stdc++.h>
using namespace std;

vector<int> findMeanExpected(vector<int> &arr, vector<vector<int>> &queries)
{
    int n = arr.size();
    int q = queries.size();
    vector<int> prefS(n, 0), res;
    prefS[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefS[i] = prefS[i - 1] + arr[i];

    for (int i = 0; i < q; i++)
    {
        int mean = 0;
        int l = queries[i][0] - 1;
        int r = queries[i][1] - 1;

        if (l == 0)
            mean = prefS[r] / (r - l + 1);
        else
            mean = (prefS[r] - prefS[l - 1]) / (r - l + 1);

        res.push_back(mean);
    }
    return res;
}

void printArr(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {3, 7, 2, 8, 5};
    vector<vector<int>> queries = {{1, 3}, {2, 5}};

    vector<int> result = findMeanExpected(arr, queries);
    printArr(result);

    arr = {10, 20, 30, 40, 50, 60};
    queries = {{4, 6}};
    result = findMeanExpected(arr, queries);
    printArr(result);
}