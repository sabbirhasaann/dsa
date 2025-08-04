// 2025/07/05 19:19:55

#include <bits/stdc++.h>
#include "graph_utils.h"
using namespace std;
#define ll long long
#define endl '\n'

void soln()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj = adjacency_input_weight(n, m);
    vector<int> shortest_path = dijkstra(adj, 0);
    for (auto i : shortest_path)
        cout << i << " ";
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