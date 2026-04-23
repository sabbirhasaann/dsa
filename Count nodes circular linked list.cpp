// 2026/04/23 07:42:02
// https://www.geeksforgeeks.org/dsa/count-nodes-circular-linked-list/

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

int countNodes(Node* head){
    if(head == nullptr)
        return 0;
    
    int cntK = 0;
    Node* curr = head;
    do{
        ++cntK;
        curr = curr->next;
    }while(curr != head);

    return cntK;
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

    vector<int> a = {1,2,3,4,5,6, 1, 2, 3, 3};
    Node* last = nullptr;
    for(int x: a)
        last = insertAtEndSingly(last, x);

    Node *head = last -> next;
    
    cout << countNodes(head) << endl;

    return 0;
}