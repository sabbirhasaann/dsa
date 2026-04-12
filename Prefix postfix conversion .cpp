// 2026/04/12 16:32:41
// https://www.geeksforgeeks.org/dsa/prefix-postfix-conversion/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isOperator(char x)
{
    switch (x) {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string prefToPost(string s){
    reverse(s.begin(), s.end());
    stack<string> st;
    string post;
    for(int i=0;i<s.length();++i){
        if((s[i]>= 'a' && s[i] <= 'z') || (s[i] >= '1' && s[i]<= '9') || (s[i] >= 'A' && s[i]<= 'Z'))
            st.push(string(1,s[i]));
        else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string ss = s1 + s2 + s[i];
            st.push(ss);
        }
    }
    return st.top();
}

int main(){
    ios_base::sync_with_stdio(false);

    string pref = "*+AB-CD";
    cout << prefToPost(pref) << endl;

    pref = "*-A/BC-/AKL";
    cout << prefToPost(pref) << endl;
    return 0;
}