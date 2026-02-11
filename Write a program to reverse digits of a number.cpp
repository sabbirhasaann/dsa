#include <bits/stdc++.h>
using namespace std;

int reverseDigits(int n){
    int digits = 0;

    while(n){
        digits =  digits * 10 + n%10;
        n/=10;
    }

    return digits;
}

int reverseDigitsRec(int n){
    if(n == 0)
        return 0;
    return n%10 + reverseDigitsRec(n/10) * 10;
}


int reverseDigitsFromString(int n) {
    
    string s = to_string(n);

    reverse(s.begin(), s.end());

    n = stoi(s);

    return n;
}

int main()
{
    int n;
    cin >> n;
    cout << reverseDigits(n) << endl;
    cout << reverseDigitsRec(n) << endl;
    cout << reverseDigitsFromString(n) << endl;
}