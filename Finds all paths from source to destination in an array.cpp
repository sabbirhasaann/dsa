#include <bits/stdc++.h>
using namespace std;

// Please remember printing all path from source to destination when
// total path length n < 25

void allpath(vector<int> &a, vector<vector<int>> &allPath, vector<int> &path, int s, int t)
{
    path.push_back(a[s]);
    if (s == t)
        allPath.push_back(path);
    else
        for (int next = s + 1; next <= t; ++next)
            allpath(a, allPath, path, next, t);
    path.pop_back();
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6};
    int n = a.size();
    vector<vector<int>> allPath;
    vector<int> path;

    allpath(a, allPath, path, 0, n - 1);

    for (int i = 0; i < allPath.size(); ++i)
    {
        for (int j = 0; j < allPath[i].size(); ++j)
            cout << allPath[i][j] << " ";
        cout << endl;
    }
}