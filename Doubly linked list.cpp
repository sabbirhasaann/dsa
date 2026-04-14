// 2026/04/14 16:35:25
// https://www.geeksforgeeks.org/dsa/doubly-linked-list/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Node{
    
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};


int main(){
    ios_base::sync_with_stdio(false);

    Node* head = new Node(10);
    
    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;

     // Create and link the fourth node
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    Node *temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}