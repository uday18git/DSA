// apna clg
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
// void sumReplacement(Node* root)
// {
//     if(!root)
//     {
//         return;
//     }
//     sumReplacement(root->left);
//     sumReplacement(root->right);
//     if(root->left)
//     {
//         root->data+=root->left->data;
//     }
//     if(root->right)
//     {
//         root->data+=root->right->data;
//     }
// }
// my answer
int sumReplacement(Node* root)
{
    if(!root)
    {
        return 0 ;
    }
    int left = sumReplacement(root->left);
    int right = sumReplacement(root->right);
    root->data+=(left+right);
    return root->data;
}
void preorder(struct Node* root){
    if(!root)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout<<"\n";
    cout<<sumReplacement(root);
    cout<<"\n";
    preorder(root);
    return 0;
}
//TIME COMPLEXITY O(N)