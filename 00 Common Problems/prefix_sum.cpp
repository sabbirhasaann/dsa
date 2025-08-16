#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<vector<int>> input_matrix(int n, int m)
{
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    return arr;
}

void print_matrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

vector<vector<int>> matrix_prefix_sum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> pre_sum(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        pre_sum[i][0] = matrix[i][0];
        for (int j = 1; j < m; j++)
            pre_sum[i][j] = pre_sum[i][j - 1] + matrix[i][j];
    }
    for (int j = 0; j < m; j++)
    {
        for (int i = 1; i < n; i++)
            pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j];
    }
    return pre_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr = input_matrix(n, m);
    vector<vector<int>> pre_sum = matrix_prefix_sum(arr);

    print_matrix(pre_sum);
}
