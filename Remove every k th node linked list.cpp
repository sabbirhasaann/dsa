// 2026/04/17 16:54:40
// https://www.geeksforgeeks.org/dsa/remove-every-k-th-node-linked-list/

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


Node* deleteK(Node *head, int k){
    if(head == nullptr || k <= 0)
        return head;
    int cnt = 0;
    Node *curr = head;
    Node *prev = nullptr;
    while(curr != nullptr){
        ++cnt;
        if(cnt % k == 0){
            if(prev != nullptr)
                prev->next = curr->next;
            else
                head = curr->next;
        }
        else
            prev = curr;
        curr = curr->next;
    }
    return head;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> a = {1,2,3,4,5,6,7,8};
    int k = 2;
    a = {2,3,4,5,6,7,8,9};

    Node *head = nullptr;
    for(int x: a)
        head = insertAtEnd(head, x);
    traverseLinkedList(head);
    
    head = deleteK(head, k);
    traverseLinkedList(head);
    return 0;
}