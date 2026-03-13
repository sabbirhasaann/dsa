// 2026/03/13 15:45:27
// https://www.geeksforgeeks.org/dsa/adding-ones/
// Range-Based - used difference array

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

void updateDiff(vector<int> &diff, int l, int r){
    diff[l] += 1;
    if(r+1<diff.size())
        diff[r+1] -= 1;
}

void update1(int a[], int n, int updates[], int k) {
        vector<int> diff(n,0);    
        for(int i=0;i<k;++i){
            int j = updates[i] - 1;
            diff[j] += 1;
        }
        
        a[0] += diff[0];
        for(int i=1;i<n;++i){
            diff[i] += diff[i-1];
            a[i] += diff[i];
        }
    }

void update(int a[], int n, int updates[], int k)
    {
        for(int i=0;i<k;i++)
            a[updates[i]-1]++;
        
        for(int i=1;i<n;i++)
            a[i] += a[i-1];
    }

void diffArray(vector<int> &a, vector<int> &idxJ){
    vector<int> diff(a.size(),0);
    for(int i: idxJ){
        updateDiff(diff, --i, a.size());
    }

    a[0] += diff[0];
    for(int i=1;i<a.size();++i){
        diff[i] += diff[i-1];
        a[i] += diff[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int N = 3, K = 4;
    vector<int> idxJ = {1, 1, 2, 3};
    vector<int> a(N, 0);
    diffArray(a, idxJ);
    printArray(a);

    fill(a.begin(), a.end(), 0);
    N = 2, K = 3;
    a.resize(N);
    idxJ = {1, 1, 1};
    diffArray(a, idxJ);
    printArray(a);

    int nn = 3;
    int arr[nn] = {0};
    int kk = 4;
    int idx[kk+1] = {0,1,1,2,3};
    update(arr, nn, idx, kk);
    for(int i=0;i<nn;++i)
        cout << arr[i] << " ";


    return 0;
}


/*
N = 3, K = 4
1 1 2 3
*/

/*
N = 2, K = 3
1 1 1
*/