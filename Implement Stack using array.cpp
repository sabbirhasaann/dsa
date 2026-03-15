// 2026/03/15 05:55:23
// https://www.geeksforgeeks.org/dsa/implement-stack-using-array/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


class myStack{
    int *arr;
    int capacity;
    int top;

public:
    myStack(int cap){
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    void push(int x){
        if(top == capacity - 1){
            cout <<"Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop(){
        if(top == -1){
            cout << "Stack underflow\n";
            return;
        }
        --top;
    }

    int peek(){
        if(top == -1){
            cout <<"Stack is empty.\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }
};


class myStackV{
    vector<int> arr;
public:
    void push(int x){
        arr.push_back(x);
    }

    void pop(){
        if(arr.empty()){
            cout << "Stack under flow.\n";
            return;
        }
        arr.pop_back();
    }

    int peek(){
        if(arr.empty()){
            cout << "Stack is empty.\n";
            return -1;
        }
    }

    bool isEmpty(){
        return arr.empty();
    }

    int size(){
        return arr.size();
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    myStack st(4);
    st.push(10);
    st.push(11);
    st.pop();
    st.pop();
    cout << st.peek();

    myStackV stv;
    stv.pop();
    cout << stv.size();
    return 0;
}