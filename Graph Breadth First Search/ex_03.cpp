// 2025/06/11 15:35:23

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void bfs(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<int> res;
    queue<int> q;

    int source = 0;
    q.push(source);
    visited[source] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        for (int x : graph[curr])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }

    for (int x : res)
        cout << x << " ";

    cout << endl;
}
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

    bfs(graph);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    soln();
    return 0;
}