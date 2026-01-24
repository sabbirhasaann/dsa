#include <bits/stdc++.h>
using namespace std;

void printTable(int n){
    for(int i=1;i<=10;i++)
        cout << n << " * " << setw(2) << i <<" : " << setw(2)<< n * i << endl;
}

void printTableRec(int n, int i=1){
    if(i==11)
        return;
    cout << n << " * " << setw(2) << i <<" : " << setw(2)<< n * i << "\n";
    printTableRec(n, ++i);
}
int main()
{
    int n;
    cin >> n;
    printTable(n);
    cout << "printTable using Recursion: \n";
    printTableRec(n);
}