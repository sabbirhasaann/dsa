#include <bits/stdc++.h>
using namespace std;

// BFS from given source s
void bfs_dis(vector<vector<int>> &adj, int s, vector<bool> &visited, vector<int> &res)
{

    // Create a queue for BFS
    queue<int> q;

    // Mark source node as visited and enqueue it
    visited[s] = true;
    q.push(s);

    // Iterate over the queue
    while (!q.empty())
    {

        // Dequeue a vertex and store it
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeued
        // vertex curr If an adjacent has not been
        // visited, mark it visited and enqueue it
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

// BFS from given source s
vector<int> bfs(vector<vector<int>> &adj)
{
    int V = adj.size();
    // Initially mark all the vertices as not visited
    vector<bool> visited(V, false);
    // create an array to store the traversal
    vector<int> res;
    // Create a queue for BFS
    queue<int> q;

    int s = 0; // source node
    q.push(s);
    // Mark source node as visited and enqueue it
    visited[s] = true;

    // Iterate over the queue
    while (!q.empty())
    {

        // Dequeue a vertex from queue and store it
        int curr = q.front();
        q.pop();
        res.push_back(curr);

        // Get all adjacent vertices of the dequeued
        // vertex curr If an adjacent has not been
        // visited, mark it visited and enqueue it
        for (int x : adj[curr])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }

    return res;
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

    // bfs(graph);
}
// Perform BFS for the entire graph which maybe
// disconnected
vector<int> bfsDisconnected(vector<vector<int>> &adj)
{
    int V = adj.size();

    // create an array to store the traversal
    vector<int> res;

    // Initially mark all the vertices as not visited
    vector<bool> visited(V, false);

    // perform BFS for each node
    for (int i = 0; i < adj.size(); ++i)
        if (!visited[i])
            bfs_dis(adj, i, visited, res);

    return res;
}

void printArray(vector<int> &ans)
{
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2, 3}, {0, 4}, {1, 4}, {2, 3}};
    vector<int> ans = bfs(adj);
    printArray(ans);

    adj = {{1, 2}, {0}, {0}, {4}, {3, 5}, {4}};
    ans = bfsDisconnected(adj);
    printArray(ans);
    return 0;
}