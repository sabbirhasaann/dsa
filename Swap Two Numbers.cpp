// 2026/02/11 08:06:12
// https://www.geeksforgeeks.org/dsa/swap-two-numbers/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

pair<int,int> swapNaive(int a, int b){
    int temp = a;
    a = b;
    b = temp;
    

    return {a,b};
}


pair<int,int> swapExpectedArithmetic(int a,int b){
    a = a + b;
    b = a - b;
    a = a - b;

    return {a,b};
}

pair<int,int> swapExpectedBitwise(int a,int b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    return {a,b};
}


int main(){
    ios_base::sync_with_stdio(false);
    int a=10, b=20;
    cout << "Before swap: " << a <<" " << b << endl;
    pair<int,int> p = swapNaive(a,b);
    cout << "After naive swap: " << p.first <<" " << p.second << endl<<endl;


    a = 10, b = 20;
    cout << "Before swap: " << a <<" " << b << endl;
    p = swapExpectedArithmetic(a,b);
    cout << "After naive swap: " << p.first <<" " << p.second << endl<<endl;

    a = 10, b = 20;
    cout << "Before swap: " << a <<" " << b << endl;
    p = swapExpectedBitwise(a,b);
    cout << "After naive swap: " << p.first <<" " << p.second << endl<<endl;


    // Using builtin
    a = 10, b = 20;
    cout << "Before swap: " << a <<" " << b << endl;
    swap(a,b);
    cout << "After naive swap: " << a <<" " << b << endl<<endl;

    return 0;
}