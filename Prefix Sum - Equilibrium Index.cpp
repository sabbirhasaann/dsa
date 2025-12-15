// 2025/12/15 06:40:55

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int findEquilibriumNaive(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int leftS, rightS;
        leftS = rightS = 0;

        for (int j = 0; j <= i; j++)
            leftS += arr[j];
        for (int j = i; j < arr.size(); j++)
            rightS += arr[j];

        if (leftS == rightS)
            return i;
    }

    return -1;
}

int findEquilibriumBetter(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefS(n, 0), suffS(n, 0);

    prefS[0] = arr[0];
    suffS[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        prefS[i] = arr[i] + prefS[i - 1];
    for (int i = n - 2; i >= 0; i--)
        suffS[i] = arr[i] + suffS[i + 1];

    for (int i = 0; i < n; i++)
        if (prefS[i] == suffS[i])
            return i;
    return -1;
}

int findEquilibriumExpected(vector<int> &arr)
{
    int prefS = 0, total = 0;
    total = accumulate(arr.begin(), arr.end(), total);

    for (int pivot = 0; pivot < arr.size(); pivot++)
    {
        int suffS = total - prefS - arr[pivot];
        if (prefS == suffS)
            return pivot;
        prefS += arr[pivot];
    }

    return -1;
}

void soln()
{

    vector<int> arr = {1, 2, 0, 3};

    cout << "FindEquillibriumNaive: " << findEquilibriumNaive(arr) << endl;

    arr = {-7, 1, 5, 2, -4, 3, 0};
    cout << "FindEquillibriumBetter: " << findEquilibriumBetter(arr) << endl;
    arr = {1, 1, 1, 1};
    arr = {-7, 1, 5, 2, -4, 3, 0};
    cout << "FindEquillibriumExpected: " << findEquilibriumExpected(arr) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}