// 2026/04/12 16:53:51
// https://www.geeksforgeeks.org/dsa/postfix-prefix-conversion/

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


string postToPref(string post){
    stack<string> st;
    for(int i=0;i<post.length();++i){
        if(isOperator(post[i])){
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string ss = post[i] + s2 + s1;
            st.push(ss);
        }
        else{
            st.push(string(1, post[i]));
        }
    }
    return st.top();
}

int main(){
    ios_base::sync_with_stdio(false);

    string post = "AB+CD-*";
    cout << postToPref(post) << endl;

    post = "ABC/-AK/L-*";
    cout << postToPref(post) << endl;


    return 0;
}

