// 2026/03/15 06:19:46
// https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Node{
public:
    int val;
    Node *next;

    Node(int x){
        val = x;
        next = NULL;
    }
};

class myStack{
    Node *top;
    int cnt;

public:
    myStack(){
        top = NULL;
        cnt = 0;
    }

    void push(int x){
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        ++cnt;
    }

    void pop(){
        if(top == NULL){
            cout << "Stack underflow.\n";
            return;
        }

        top = top->next;
        --cnt;
    }

    int peek(){
        if(top == NULL){
            cout << "Stack is empty\n";
            return -1;
        }
        return top->val;
    }

    bool isEmpty(){
        return top == NULL;
    }

    int size(){
        return cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    
    myStack st;
    cout << st.size() << endl;
    cout << st.isEmpty();
    st.push(10);
    cout << st.size() << endl;
    return 0;
}