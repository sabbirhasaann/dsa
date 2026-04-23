// 2026/04/23 07:12:30
// https://www.geeksforgeeks.org/dsa/check-if-a-linked-list-is-circular-linked-list/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
};

bool isCircular(Node* head){
    Node* curr = head;
    while(curr && curr->next != head){
        curr = curr->next;
    }
    if(!curr)
        return false;
    return true;
}

Node* insertAtEnd(Node *head, int x){
    Node *newNode = new Node(x);
    if(head == nullptr)
        return newNode;
    Node *curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

void traverseLinkedList(Node *head){
    Node *curr = head;
    while(curr != nullptr){
        cout << curr->data <<" ";
        curr = curr->next;
    }
    cout << endl;
}


Node* insertAtEndSingly(Node* last, int data){
    Node* newNode = new Node(data);
    
    if(last == nullptr){
        last = newNode;
        newNode-> next = last;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}


void traverseSinglyCircular(Node* last){
    if(last == nullptr){
        cout << "Linked list is empty.\n";
        return;
    }
    Node *head = last->next;
    Node *curr = head;

    do{
        cout << curr -> data <<" ";
        curr = curr->next;
    }while(curr != head);
    cout << endl;    
}


int main(){
    ios_base::sync_with_stdio(false);

    vector<int> a = {1,2,3,4,5,6};
    Node *headS = nullptr;
    for(int x: a)
        headS = insertAtEnd(headS, x);
    traverseLinkedList(headS);
    
    isCircular(headS)
    ? cout <<"Circular Singly Linked List."
    : cout << "Singly Linked List.";

    Node *headCS = nullptr;
    for(int x: a)
        headCS = insertAtEndSingly(headCS, x);
    traverseSinglyCircular(headCS);

    isCircular(headCS)
    ? cout <<"Circular Singly Linked List."
    : cout << "Singly Linked List.";

    return 0;
}