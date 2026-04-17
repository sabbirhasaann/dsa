// 2026/04/14 16:50:44
// https://www.geeksforgeeks.org/dsa/circular-linked-list/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class NodeSingly{
public:
    int data;
    NodeSingly* next;
    NodeSingly(int value){
        data = value;
        next = nullptr;
    }
};

void SinglyCircular(){
    NodeSingly* head = new NodeSingly(10);
    NodeSingly* node1 = new NodeSingly(20);
    NodeSingly* node2 = new NodeSingly(30);
    NodeSingly* node3 = new NodeSingly(40);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = head;

    NodeSingly* temp = head;
    while(temp->next != head){
        cout << temp->data <<" ";
        temp = temp->next;
    }

}


/* Doubly Circular */
class NodeDoubly{
public:
    int data;
    NodeDoubly *next;
    NodeDoubly *prev;
    NodeDoubly(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

void DoublyCircluar(){
    
}

pair<NodeSingly*, NodeSingly*> insertAtEndSingly(NodeSingly* head, NodeSingly* last, int data){
    NodeSingly* newNode = new NodeSingly(data);
    
    if(head == nullptr){
        head = newNode;
        last = newNode;
        newNode -> next = head;
    }
    else{
        last->next = newNode;
        last = newNode;
        last->next = head;
    }

    return {head, last};
}

int main(){
    ios_base::sync_with_stdio(false);

    vector<int> a = {1,2,3,4,5};
    pair<NodeSingly*, NodeSingly*> hl{nullptr, nullptr}; 
    
    for(int x: a)
        hl = insertAtEndSingly(hl.first, hl.second, x);

    NodeSingly* temp = hl.first;
    if(hl.first == nullptr)
        cout <<"Empty list\n";
    else{
        // while(temp->next != hl.first){
        //     cout << temp->data << " ";
        //     temp = temp->next;
        // }
        // cout << temp->data << endl;

        /* efficient way for traverse circular singly linked list*/
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != hl.first);
    }
    

    
    /* singly circular */
    // SinglyCircular();

    /* doubly circular */
    // DoublyCircluar();

    return 0;
}