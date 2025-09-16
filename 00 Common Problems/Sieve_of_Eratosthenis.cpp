#include <iostream>
using namespace std;

int main()

{
    int n;
    cin >> n;

    int prime[n+1]={1};
    prime[0]=prime[1] = 0;

    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1 && ((long long)i*i <= n))
        {
            for(int j=i*i;j<=n;j+=i)
                prime[j] = 0;
        }
    }


    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
            cout << i <<"\n";
    }

    return 0;
}
