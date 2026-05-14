// 2026/05/14 09:10:56
// https://www.geeksforgeeks.org/dsa/array-implementation-of-queue-simple/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class myQueue
{
    int capacity;
    int *arr;
    int size;

public:
    myQueue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    void enqueue(int x)
    {
        if (size == capacity)
        {
            cout << "Queue overflowed!\n";
            return;
        }
        arr[size++] = x;
    }

    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is underflowed!\n";
            return;
        }
        for (int i = 1; i < size; ++i)
            arr[i - 1] = arr[i];
        --size;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    myQueue q(3);
    q.enqueue(12);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front();

    return 0;
}