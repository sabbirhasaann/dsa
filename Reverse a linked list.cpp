// 2026/05/07 16:04:29
// https://www.geeksforgeeks.org/dsa/reverse-a-linked-list/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};

Node *insertAtEnd(Node *head, int x)
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
    return head;
}

void traverseLinkedList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *reverseList(Node *head)
{
    Node *curr = head, *prev = nullptr, *next;
    while (curr != nullptr)
    {
        next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *reverseListRec(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *rest = reverseListRec(head->next);

    head->next->next = head;

    head->next = nullptr;

    return rest;
}

Node *reverseListStack(Node *head)
{

    stack<Node *> s;
    Node *temp = head;

    while (temp->next != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }

    head = temp;

    while (!s.empty())
    {

        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> a = {1, 2, 3, 4, 5, 6};
    Node *head = nullptr;

    for (int x : a)
        head = insertAtEnd(head, x);
    traverseLinkedList(head);
    head = reverseList(head);
    traverseLinkedList(head);
    head = reverseListRec(head);
    traverseLinkedList(head);
    head = reverseListStack(head);
    traverseLinkedList(head);

    return 0;
}