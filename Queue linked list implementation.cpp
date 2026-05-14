// 2026/05/14 10:49:34
// https://www.geeksforgeeks.org/dsa/queue-linked-list-implementation/

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

class myQueue
{
public:
    Node *front;
    Node *rear;
    int currSize;
    myQueue()
    {
        front = rear = nullptr;
        currSize = 0;
    }

    void enqueue(int x)
    {
        Node *temp = new Node(x);

        if (front == nullptr)
        {
            rear = temp;
            front = rear;
        }
        else
            rear->next = temp;
        ++currSize;
    }

    int getFront()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!\n";
            return -1;
        }

        return rear->data;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!\n";
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;
        delete temp;
        --currSize;
    }

    int size()
    {
        return currSize;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    myQueue q;
    q.enqueue(10);
    cout << q.size() << endl;
    cout << q.getFront() << endl;
    q.enqueue(12);

    return 0;
}