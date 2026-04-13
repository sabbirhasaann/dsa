// 2026/04/13 11:08:09
// https://www.geeksforgeeks.org/dsa/check-for-balanced-parentheses-in-an-expression/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.length();++i){
        char c = s[i];
        if(st.empty() || c == '[' || c == '{' || c == '(')
            st.push(c);
        else{
            int t = st.top();
            if((t=='(' && c==')') || (t=='{' && c=='}') || (t=='[' && c==']'))
                st.pop();
            else
                st.push(c);
                
        }
    }
    return st.empty();
}

bool isBalanced(string& s) {
   
    stack<char> st; 
   
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        
        else if (c == ')' || c == '}' || c == ']') {
            
            // No opening bracket
            if (st.empty()) return false; 
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
            
            st.pop(); 
        }
    }
    
    return st.empty(); 
}

int main(){
    ios_base::sync_with_stdio(false);

    string parentheses = "[()()]{}";
    isValid(parentheses) ? cout << "Valid\n" : cout << "Invalid\n";

    parentheses = "([{]})";
    isValid(parentheses) ? cout << "Valid\n" : cout << "Invalid\n";

    return 0;
}