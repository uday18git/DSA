// approach 1-> take any two n1 and n2 nodes take the path between root and these nodes .. the point of divergence will be the lowest common ancestor
// approach 2-> from a specific node if right side has n1/n2 and left side also has n1/n2, then that is the lca
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
bool getPath(Node *root, int key, vector<int> &path)
{
    if(!root)return false;
    path.push_back(root->data);
    if(root->data==key)
    {
        return true;
    }  
    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}
int lca(Node* root,int n1,int n2)
{
    vector<int> path1,path2;
    if(!getPath(root,n1,path1) || !getPath(root,n2,path2))return -1;
    int pc;
    for(pc=0;pc<path1.size() && path2.size();pc++)
    {
        if(path1[pc]!=path2[pc])
        {
            break;
        }
    }
    return path1[pc-1];
}
Node* LCA2(Node *root, int n2, int n1)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node* leftLCA = LCA2(root->left, n2, n1);
    Node* rightLCA = LCA2(root->right, n2, n1);
    if (leftLCA && rightLCA)
    {
        return root;
    }
    if (leftLCA) // because if leftLCA != null we will return leftLCA
    {
        return leftLCA;
    }
    return rightLCA;
}
// Node* LCA2(Node *root, int n2, int n1)
// {
//     if(!root)return NULL;
//     if(root->data==n1 || root->data==n2)return root;
//     Node* leftLCA = LCA2(root->left,n2,n1);
//     Node* rightLCA = LCA2(root->right,n2,n1);
//     if(leftLCA && rightLCA)return root;
//     if(!rightLCA && !leftLCA)return NULL;
//     if(!leftLCA)return rightLCA;
//     return leftLCA;
// }
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node *lca = LCA2(root, 5, 4);
    if (!lca)
        cout << "not exist" << endl;
    cout << lca->data;
    return 0;
}