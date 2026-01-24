#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i=2;i*i<=n;i++){
        if(prime[i])
            for(int j=i*i; j <= n; j+=i)
                prime[j] = false;
    }
 
    for(int i=0;i<n;i++)
        if(prime[i])
            primes.push_back(i);

    return primes;
            
}
void printArray(vector<int> &v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >>n;
    vector<int> primes = sieve(n);
    printArray(primes);
}