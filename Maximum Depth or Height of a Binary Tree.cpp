#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int heightRec(Node *root)
{
    if (root == nullptr)
        return -1;

    int lheight = heightRec(root->left);
    int rheight = heightRec(root->right);

    return 1 + max(lheight, rheight);
}

int height(Node *root)
{
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);

    int height = 0;
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }

        height++;
    }

    return height - 1;
}

int main()
{
    Node *root = new Node(0);
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    cout << "Height of the binary tree (Recursion): " << heightRec(root) << endl;
    cout << "Height of the binary tree (Level Order Traversal): " << height(root) << endl;
}