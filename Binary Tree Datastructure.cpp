#include <bits/stdc++.h>
using namespace std;

// Node structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createABinaryTreeLabelOrderFromArray(vector<int> &a){
    
    if(a.empty())
        return nullptr;

    TreeNode *root = new TreeNode(a[0]);

    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty()){
        TreeNode *current = q.front();
        q.pop();
        if(i<a.size()){
            current->left = new TreeNode(a[i]);
            q.push(current->left);
            ++i;
        }
        if(i<a.size()){
            current->right = new TreeNode(a[i]);
            q.push(current->right);
            ++i;
        }
    }

    return root;
}

void printTreeInOrder(TreeNode* root){
    if(root == nullptr)
        return;
    
    printTreeInOrder(root->right);
        cout << root->val << " ";
    printTreeInOrder(root->left);
}

void printTreePreOrder(TreeNode* root){
    if(root == nullptr)
        return;
    
    cout << root->val << " ";
    printTreePreOrder(root->right);
    printTreePreOrder(root->left);
}

void printTreePostOrder(TreeNode* root){
    if(root == nullptr)
        return;
    
    printTreePostOrder(root->right);
    printTreePostOrder(root->left);
    cout << root->val << " ";
}

void printTreeLevelOrder(TreeNode *root){
    if(root == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int len = q.size(), i=0;
        while (i<len)
        {   
            TreeNode *current = q.front();
            q.pop();

            cout << current->val <<" ";

            if(current->left != nullptr)
                q.push(current->left);

            if(current->right != nullptr)
                q.push(current->right);
            ++i;
        }
        
    }
    
}

int main()
{
    // Initilize and allocate memory for tree nodes
    TreeNode* firstNode = new TreeNode(2);
    TreeNode* secondNode = new TreeNode(3);
    TreeNode* thirdNode = new TreeNode(4);
    TreeNode* fourthNode = new TreeNode(5);

    // Connect binary tree nodes
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = fourthNode;

    printTreeInOrder(firstNode);
    cout << endl;

    vector<int> a = {1,0,1,0,1,0,1};
    TreeNode* root = createABinaryTreeLabelOrderFromArray(a);
    printTreeLevelOrder(root);
}