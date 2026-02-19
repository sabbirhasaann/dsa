#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void rule6(){

    int n = 1000;
    for(int i=1;i<=n;++i){
        cout << i <<" * " << 6 << " : " << i * 6 << "\t\t" << i << " * " << 2 <<" : " << i * 2 << endl;
    }

}

void r1(){
    long long l = 1;
    long long r = 100000;

    for(long long i=l;i<=r;++i){
        long long t = 31,n=i;
        cout << "n - " <<n <<" : ";
        while(t--){
            if(n==1)
                break;
            
            if(n%6 == 0){
                cout << n/6 <<" ";
                n/=6;
            }
            else
            {
                cout << 2 * n <<" ";
                n *= 2;
            }
        }
        cout << endl;
    }
}

void printArray(vector<long long> &v)
{
    for (long long x : v)
        cout << x << "\n";
    cout << endl;
}

void pattern(){
    vector<long long> v;
    unordered_map<long long,int> mp;
    ++mp[1];
    v.push_back(1);
    v.push_back(3);

    queue<long long> q;
    q.push(3);

    while(!q.empty()){
        long long n = q.front();
        q.pop();

        long long l = 2 * n;
        long long r = 3 * n;

        if(l < INT_MAX && mp.find(l) == mp.end())
        {
            ++mp[l];
            v.push_back(l);
            q.push(l);
        }
        if(r < INT_MAX && mp.find(r) == mp.end()){
            ++mp[r];
            v.push_back(r);
            q.push(r);
        }
    }

    printArray(v);
}

int main()
{
    // rule6();
    // r1();
    pattern();
}