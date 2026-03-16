// 2026/03/14 16:09:50
// https://www.geeksforgeeks.org/dsa/shortest-path-unweighted-graph/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void bfs(vector<vector<int>> &adj, int s, int d){
    
    int V = adj.size();
    vector<int> parent(V,-1);
    vector<int> dist(V, 1e9);
    queue<int> q;

    q.push(s);
    dist[s] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int u: adj[v]){
            if(dist[u] == 1e9){
                parent[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    if(parent[d] == 1e9){
        cout <<"No path from source to destination.";
        return;
    }
    
    else{
        vector<int> path;
        int curr = d;
        path.push_back(d);

        while (parent[curr] != -1)
        {
            path.push_back(parent[curr]);
            curr = parent[curr];
        }


        for(int i=path.size()-1;i>=0;--i)
            cout << path[i] <<" ";
        cout << endl;
    }

    

}

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);

    
    int V = 8, E = 10, S = 0, D = 7;
    int edges[E][2] = {{0, 1}, 
                    {1, 2}, 
                    {0, 3}, 
                    {3, 4}, 
                    {4, 7}, 
                    {3, 7}, 
                    {6, 7}, 
                    {4, 5}, 
                    {4, 6}, 
                    {5, 6}};

    vector<vector<int>> adj(V);
    for(int i=0;i<E;++i){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    bfs(adj,S,D);

    
    /*
    output
    The shortest path is 0 -> 3 -> 7.
    */
    

    // V = 8, E = 10, S = 2, D = 6, edges[][] = {{0, 1}, {1, 2}, {0, 3}, {3, 4}, {4, 7}, {3, 7}, {6, 7}, {4, 5}, {4, 6}, {5, 6}}
    return 0;
}



/*input
8 10
0 1 
1 2 
0 3 
3 4 
4 7 
3 7 
6 7 
4 5 
4 6 
5 6
*/

/*output
0 -> 3 -> 7
*/