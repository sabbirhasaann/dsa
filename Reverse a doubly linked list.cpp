// 2026/05/07 18:09:52
// https://www.geeksforgeeks.org/dsa/reverse-a-doubly-linked-list/

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
    vector<int> a = {1, 2, 3, 4, 5};
    Node *head = nullptr;

    for (int x : a)
        head = insertAtBeginDoubly(head, x);
    traverseDoublyLinkedList(head);

    for (int x : a)
        head = insertAtEndDoubly(head, x);
    traverseDoublyLinkedList(head);

    return 0;
}