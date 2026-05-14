// 2026/05/14 09:25:56
// https://www.geeksforgeeks.org/dsa/introduction-to-circular-queue/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class myQueue
{
private:
    int *arr;
    int capacity;
    int front;
    int size;

public:
    myQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = size = 0;
    }

    void enqueue(int x)
    {
        if (size == capacity)
        {
            cout << "Queue is overflowed!\n";
            return;
        }

        int rear = (front + size) % capacity;
        arr[rear] = x;
        ++size;
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is underflowed!\n";
            return;
        }
        front = (front + 1) % capacity;
        --size;
    }

    int getFront()
    {
        if (size == 0)
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (size == 0)
            return -1;
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    myQueue q(3);
    q.enqueue(1);
    cout << q.getFront() << endl;
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    cout << q.getFront() << endl;
    q.enqueue(4);
    q.dequeue();
    q.dequeue();

    cout << q.getFront() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}