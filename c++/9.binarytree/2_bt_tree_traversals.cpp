// preorder -> VLR
// postorder -> LRV
// inorder -> LVR
#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
void preorder(struct Node* root){
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root){
    
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
void postorder(struct Node* root){
    
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}