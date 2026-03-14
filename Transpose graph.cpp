// 2026/03/14 15:50:21
// https://www.geeksforgeeks.org/dsa/transpose-graph/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<vector<int>> transposeGraph(vector<vector<int>>adj, int v){
    vector<vector<int>> trans(v);

    for(int i=0;i<v;++i){
        for(int u: adj[i])
            trans[u].push_back(i);
    }

    return trans;
}

int main(){
    ios_base::sync_with_stdio(false);

    int v,e;
    cin >> v >> e;
    vector<vector<int>> adj(v);
    for(int i=0;i<e;++i){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<vector<int>> trans = transposeGraph(adj, v);
    for(int i=0;i<v;++i){
        cout << i <<"--> ";
        for(int u: trans[i])
            cout << u << " ";
        cout << endl;
    }


    return 0;
}

/*input
5 7
0 1
0 3
0 4
2 0
3 2
4 1
4 3
*/