#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
Node* insertBST(Node *root, int val)
{
    if (!root)
    {
        return new Node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}
// approach1 node>left child.. node<right child then WRONG APPROACHHHHHH!!! comparision is being done only with one left subtree and right subtree node not the whole subtree
//  APPROACH 2 --> FIND MAXL of left subtree AND MINR of right subtree node>maxL , node < minR
//  approach 3 --> minimum allowed and maximum allowed , we are traversing only once and node<maxallowed and node>min allowed
bool isBST(Node *root, int maxa, int mina)
{
    if (!root)
        return true;
    if (root->data > maxa || root->data < mina)
        return false;
    bool left = isBST(root->left, root->data, mina);
    bool right = isBST(root->right, maxa, root->data);
    return (left && right);
        
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->right->right = new Node(9);
    if (isBST(root, INT_MAX, INT_MIN))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

// LEETCODE SOLUTION

class Solution
{
public:
    bool check(TreeNode *root, long long int mina, long long int maxa)
    {
        if (!root)
            return true;
        if (root->val <= mina || root->val >= maxa)
            return false;
        bool left = check(root->left, mina, root->val);
        bool right = check(root->right, root->val, maxa);
        return left && right;
    }
    bool isValidBST(TreeNode *root)
    {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};