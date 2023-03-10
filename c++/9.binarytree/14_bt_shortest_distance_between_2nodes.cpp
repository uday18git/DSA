//minimum number of edges needed to traverse from n1 to n2
//always minimum distance will be through the lca so we can use this to our addvantage

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
Node* LCA(Node* root,int n1,int n2)
{
    if(!root)return NULL;
    if(root->data==n1 || root->data==n2)return root;
    Node* leftLCA= LCA(root->left,n1,n2);
    Node* rightLCA= LCA(root->right,n1,n2);
    if(rightLCA && leftLCA)return root;
    if(!rightLCA && !leftLCA)return NULL;
    if(!leftLCA)return rightLCA;
    return leftLCA;
}
//STRATEGY => 1. WE WILL FIND OUT LCA
// 2. WILL CALCULATE DISTANCE FROM LCA TO BOTH THE NODES N1 AND N2 i.e D1 AND D2
// 3. THEN D1+D2
int findDist(Node* root,int k,int dist)
{
    if(!root)return -1;
    if(root->data==k)return dist;
    int left = findDist(root->left,k,dist+1);
    if(left!=-1)return left;//if the k we are trying to find is not on the left it will give -1 so we will call the function on right
    return findDist(root->right,k,dist+1);
}
int Distance(Node* root,int n1,int n2)
{
    Node* lca = LCA(root,n1,n2);
    int d1 = findDist(lca,n1,0);
    int d2 = findDist(lca,n2,0);
    return d1+d2;
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
    cout<<Distance(root,1,1);
    return 0;
}