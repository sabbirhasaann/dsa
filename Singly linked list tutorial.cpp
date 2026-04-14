// 2026/04/14 16:33:13
// https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


// Definition of a Node in a singly linked list
// class Node {
  
// public:
//     // Data part of the node
//     int data;

//     // Pointer to the next node in the list
//     Node* next;

//     // Constructor to initialize the node with data
//     Node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };



// singly linked list node structure
class Node {
public:
    int data;
    Node* next;

    // constructor to initialize a new node with data
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    
    // Create the first node (head of the list)
    Node* head = new Node(10);

    // Link the second node
    head->next = new Node(20);

    // Link the third node
    head->next->next = new Node(30);

    // Link the fourth node
    head->next->next->next = new Node(40);

    // printing linked list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}