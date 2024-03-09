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
// to find number of nodes in a bt left_subtree_count + right_subtree_count + 1
int countNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return countNodes(root->left)+countNodes(root->right)+1;
}
int SumNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return SumNodes(root->left)+SumNodes(root->right)+root->data;
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
    cout<<SumNodes(root);
    return 0;
}
// IF ITS GIVEN THAT ITS A COMPLETE BINARY TREE THEN WE CAN USE THE PROPERTY THAT IF LEFT HEIGHT IS === RIGHT HEIGHT
// NUMBER OF NODES  = 2^HEIGHT -1
