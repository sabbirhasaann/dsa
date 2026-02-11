// 2026/02/11 08:36:00
// https://www.geeksforgeeks.org/dsa/the-dice-problem/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int oppositeFaceOfDiceNaive(int n) {
    int ans;
    if(n==1){
        ans = 6;
    }else if(n==2){
        ans = 5;
    }else if(n==3){
        ans = 4;
    }else if(n==4){
        ans = 3;
    }else if(n==5){
        ans = 2;
    }else{
        ans = 1;
    }
    return ans; 
}

int oppositeFaceOfDiceExpect(int n){
    return 7 - n;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n = 2;
    cout << oppositeFaceOfDiceNaive(n) << endl;

    cout << oppositeFaceOfDiceExpect(n) << endl;

    

    return 0;
}