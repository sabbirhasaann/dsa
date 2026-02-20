#include <bits/stdc++.h>
using namespace std;

vector<int> removeConsecutiveDuplicate(vector<int> &a){
    int k = 0;
    int n = a.size(),i;
    vector<int> res;
    for(i=1;i<n;++i){
        if(a[i-1] != a[i])
            res.push_back(a[i-1]);
    }
    res.push_back(a[i-1]);
    return res;
}

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}
int main()
{
    vector<int> a = {1,3,3,1,5,5,5,1,1,3};
    a = {1,1,2,2,2,3,1};
    vector<int> aprime = removeConsecutiveDuplicate(a);
    printArray(aprime);
}