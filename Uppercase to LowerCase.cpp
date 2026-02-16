// 2026/02/16 13:16:13
// https://www.geeksforgeeks.org/dsa/uppercase-to-lowercase/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char lowerBitwise(char upper){
    return upper | 32;
}

char upperBitwise(char lower){
    return lower ^ 32;
}
char lowerAdd32(char upper){
    return upper + 32;
}

char upperSubtract32(char lower){
    return lower - 32;
}


int main(){

    ios_base::sync_with_stdio(false);

    char upper = 'A';
    char lower = 'z';
    cout << lowerAdd32(upper) << endl; 
    cout << lowerBitwise(upper) << endl;
    cout << upperBitwise(lower) << endl;
    cout << upperSubtract32(lower) << endl;

    return 0;
}