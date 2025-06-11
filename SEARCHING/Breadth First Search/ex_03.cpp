// 2025/06/11 15:35:23

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void soln()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> graph(vertices, vector<int>());
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        soln();
    return 0;
}