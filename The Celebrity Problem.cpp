// 2026/03/15 07:08:24
// https://www.geeksforgeeks.org/dsa/the-celebrity-problem/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int celebrityStack(vector<vector<int>> &mat){
    int n = mat.size();
    stack<int> s;
    for(int i=0;i<n;++i)
        s.push(i);
    
    while (s.size()>1)
    {   
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if(mat[a][b])
            s.push(b);
        else
            s.push(a);
    }

    int c = s.top();
    s.pop();

    for(int i=0;i<n;++i){
        if(i==c)
            continue;
        if(mat[c][i] || !mat[i][c])
            return -1;
    }

    return c;
}

int celebrityTwoP(vector<vector<int>> &mat){
    int n  = mat.size();

    int i=0,j=n-1;
    while(i<j){
        if(mat[i][j])
            ++i;
        else
            --j;
    }
    // cout << i << " " << j << endl;
    int c = i;
    for(int i=0;i<n;++i){
        if(i==c)
            continue;
        if(mat[c][i] || !mat[i][c])
            return -1;
    }
    

    return c;
}

int main(){
    ios_base::sync_with_stdio(false);

    vector<vector<int> > mat = {{ 1, 1, 0 },
                                { 0, 1, 0 },
                                { 0, 1, 1 }};
    cout << celebrityStack(mat) << endl;
    cout << celebrityTwoP(mat) << endl;
    return 0;
}