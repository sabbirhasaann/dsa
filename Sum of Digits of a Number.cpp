#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n){
    
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int sumOfDigitsRec(int n){
    if(n == 0)
        return 0;
    return n % 10 + sumOfDigits(n/10);
}


int sumOfDigitsFromString(int n) {
    
    string s = to_string(n);  
    int sum = 0;

    for (char ch : s) {
        sum += ch - '0';
    }
    return sum;
}


int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n)<<endl;
    cout << sumOfDigitsRec(n) << endl;
    cout << sumOfDigitsFromString(n) << endl;
}