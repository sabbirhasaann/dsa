// 2026/04/14 16:35:25
// https://www.geeksforgeeks.org/dsa/doubly-linked-list/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Node
{

public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

Node *insertAtEndDoubly(Node *head, int x)
{
    Node *newNode = new Node(x);
    if (head == nullptr)
        return newNode;

    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->prev = curr;

    return head;
}

Node *insertAtBeginDoubly(Node *head, int x)
{
    Node *newNode = new Node(x);

    if (head == nullptr)
        return newNode;

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

void traverseDoublyLinkedList(Node *head)
{
    if (head == nullptr)
        return;
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void traverseBackwardDoubly(Node *head)
{
    if (head == nullptr)
        return;

    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }

    cout << "Backward: ";
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    Node *head = new Node(10);

    head->next = new Node(20);
    head->next->prev = head;

    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    // Create and link the fourth node
    head->next->next->next = new Node(40);
    head->next->next->next->prev = head->next->next;

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}