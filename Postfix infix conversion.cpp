// 2026/04/13 10:50:59
// https://www.geeksforgeeks.org/dsa/postfix-infix-conversion/

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

string postToInfix(string post){
    stack<string> st;
    for(int i=0;i<post.length();++i){
        if(isOperator(post[i])){
            string s2 = st.top();
            st.pop();
            string s1 = st.top();
            st.pop();
            string s = '(' + s1 + post[i] + s2 + ')';
            st.push(s);
        }
        else
            st.push(string(1,post[i]));
    }
    return st.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    string post = "AB+CD-*";
    cout << postToInfix(post) << endl;    

    return 0;
}