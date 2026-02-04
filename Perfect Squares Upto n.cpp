// 2026/02/04 10:59:42

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
void soln()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i=2;i*i<=n;i++)
        a.push_back(i*i);
    for(int x: a)  
        cout << x << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    soln();
    return 0;
}