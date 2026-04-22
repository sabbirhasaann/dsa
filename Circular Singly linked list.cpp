// 2026/04/22 07:00:36
// https://www.geeksforgeeks.org/dsa/deletion-circular-linked-list/

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

void traverseSinglyCircular(NodeSingly* last){
    if(last == nullptr){
        cout << "Linked list is empty.\n";
        return;
    }
    NodeSingly *head = last->next;
    NodeSingly *curr = head;

    do{
        cout << curr -> data <<" ";
        curr = curr->next;
    }while(curr != head);
    cout << endl;    
}

NodeSingly* insertAtBeginningSingly(NodeSingly* last, int data){
    NodeSingly* newNode = new NodeSingly(data);
    if(last == nullptr){
        last = newNode;
        newNode->next = last;
    }
    else{
        newNode->next = last->next;
        last->next = newNode;
    }
    return last;
}

NodeSingly* deleteAtBeginningSingly(NodeSingly* last){
    if(last == nullptr){
        cout << "List is empty!\n";
        return nullptr;
    }

    NodeSingly* head = last->next;
    if(head == last){
        delete head;
        last = nullptr;
    }
    else{
        last->next = head->next;
        delete head;
    }

    return last;
}

NodeSingly* insertAtSpecificPosSingly(NodeSingly* last, int data, int pos){
    NodeSingly* newNode = new NodeSingly(data);
    if(last == nullptr){
        last = newNode;
        newNode->next = last;
    }

    return last;
}

NodeSingly* insertAtEndSingly(NodeSingly* last, int data){
    NodeSingly* newNode = new NodeSingly(data);
    
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

NodeSingly* deleteAtEndSingly(NodeSingly* last){
    if(last == nullptr){
        cout << "List is empty!\n";
        return nullptr;
    }

    NodeSingly* head = last->next;
    if(head == last){
        delete head;
        last = nullptr;
    }
    else{
        NodeSingly* curr = last->next;
        while(curr->next != last){
            curr = curr->next;
        }
        curr->next = last->next;
        delete last;
        last = curr;
    }
    return last;
}

int main(){
    ios_base::sync_with_stdio(false);

    vector<int> a = {1,2,3,4,5};
    NodeSingly* last = nullptr;
    traverseSinglyCircular(last);
    for(int x: a)
        last = insertAtEndSingly(last,x);
    traverseSinglyCircular(last);
    for(int x: a)
        last = insertAtBeginningSingly(last, x);
    traverseSinglyCircular(last);
    
    for(int i=0;i<11;++i){
        last = deleteAtEndSingly(last);
        traverseSinglyCircular(last);
    }

    return 0;
}