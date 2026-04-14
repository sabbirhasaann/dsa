// 2026/04/14 16:01:42
// https://www.geeksforgeeks.org/dsa/reversing-first-k-elements-queue/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

/* solution - 1*/

void reverseFirstK(queue<int> &q, int k){
    if(k==0)
        return;
    int x = q.front();
    q.pop();
    reverseFirstK(q, --k);
    q.push(x);
}

void moveNkToEnd(queue<int> &q, int k){
    if(k==0)
        return;
    int x = q.front();
    q.pop();
    q.push(x);
    moveNkToEnd(q, --k);
}


/* solution - 2*/

void revFirstK(queue<int> q, int k){
    if (q.empty() == true || k > q.size())
        return;
    if (k <= 0)
        return;

    stack<int> s;

    // Push the first K elements
    //   into a Stack
    
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue the contents of stack
    //   at the back of the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Remove the remaining elements and
    //   enqueue them at the end of the Queue
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    int k = 3;

    /* solution - 1*/

    reverseFirstK(queue,k);
    moveNkToEnd(queue, 2);
    while(!queue.empty()){
        int x = queue.front();
        cout << x << " ";
        queue.pop();
    }


    /* solution - 2*/

    return 0;
}