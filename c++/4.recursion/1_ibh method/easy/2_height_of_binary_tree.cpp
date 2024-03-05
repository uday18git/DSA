// height of a binary tree , suppose there is a binary tree , just draw lines over the tree on each level , number of lines is the height
#include <iostream>
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
int height(Node * root)
{
    if(root==NULL) // smallest valid input
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}