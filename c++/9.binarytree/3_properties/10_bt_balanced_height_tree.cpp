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
int Height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lheight = Height(root->left);
    int rheight = Height(root->right);
    return max(lheight,rheight)+1;

}
//BALANCED HEIGHT TREE IS WHOSE LEFT SUBTREE HEIGHT AND RIGHT SUBTREE HIEGHT DIFFERENCE IS <=1
// LOGIC IS WE WILL CHECK LEFT SUBTREE IS BALANCED OR NOT THEN RIGHT SUBTREE IS BALANCED OR NOT .. THEN WE'LL TAKE DIFFERNCE TO SEE CURRENT NODE IS BALANCED OR NOT RECURSIVELY
bool isBalanced(Node* root)//this is O(N^2) lol
{
    if(!root)return true;
    if(!isBalanced(root->left))return false;
    if(!isBalanced(root->right))return false;
    if(abs(Height(root->left)-Height(root->right))>1)return false;
    else return true;
}
// more intuitive
// check if left is balanced
// check if right is balanced 
// and return left && right && abs(height(root->left)-height(root->right))<2;
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        return left && right && abs(height(root->left)-height(root->right))<2;
    }
};

bool optisBalanced(Node* root,int* height)//this is O(N) lol
{
    if(!root)return true;
    int lh=0,rh=0;
    if(!optisBalanced(root->left,&lh))return false;
    if(!optisBalanced(root->right,&rh))return false;
    *height=max(lh,rh)+1;
    if(abs(lh-rh)>1)return false;
    else return true;
}


int main()
{
    int height=0;
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    if(optisBalanced(root,&height))
    {
        cout<<"Balanced"<<endl;
    }
    else
    {
        cout<<"Not balanced"<<endl;
    }
    return 0;
}