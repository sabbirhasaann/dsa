#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {

    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    
    dist[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;  
        int u = top.second; 

        if (d > dist[u])
            continue;

        for (auto &p : adj[u]) {
            int v = p.first; 
            int w = p.second; 

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;   
                pq.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

vector<int> dijkstra1(vector<vector<pair<int,int>>> &adj, int s){
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,s});
    dist[s] = 0;

    while(!pq.empty()){
        pair<int,int> top = pq.top();
        int d = top.first;
        int u = top.second;
        pq.pop();
        
        if(d>dist[u])
            continue;

        for(pair<int,int> p: adj[u]){
            int v = p.first;
            int w = p.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;

}

int main()
{
    int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};

    vector<int> result = dijkstra(adj, src);

    for (int d : result)
        cout << d << " ";
    cout << " ";



    // int n,e;
    // cin >> n >> e;
    // vector<vector<pair<int,int>>> adj(n);
    // int i=0;
    // while(i<n){
    //     int u,v,w;
    //     cin >> u >> v >> w;
    //     adj[u].push_back({v,w});
    //     adj[v].push_back({u,w});
    //     ++i;
    // }

    // vector<int> path = dijkstra(adj, 0);
    // printArray(path);
}

/*input
5 5
0 1 4
0 2 8
1 2 3
1 4 6
2 3 2
3 4 10
*/

/*output
0 4 7 9 10
*/