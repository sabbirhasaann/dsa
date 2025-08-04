// 2025/07/31 16:46:46

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<vector<pair<int, int>>> adjacency_list(int n, int m)
{
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    return adj;
}

void print_adjacency_list(vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> x : adj[i])
            cout << x.first << " ";
        cout << endl;
    }
}
void soln()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj = adjacency_list(n, m);
    print_adjacency_list(adj);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}