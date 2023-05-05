///check is data is equal , check if left subtrees are same and check if right subtrees are same
#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    Node* right,*left;
    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};
bool identical(Node* root1,Node* root2)
{
    if(!root1 && !root2)return true;
    else if(!root1 && root2)return false;
    else if(root1 && !root2)return false;
    return root1->data==root2->data && identical(root1->left,root2->left) && identical(root1->right,root2->right);
}
int main()
{
    struct Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    // root1->left->left = new Node(4);
    // root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(6);
    if(identical(root1,root))cout<<"identical"<<endl;
    else cout<<"Not identical"<<endl;
    return 0;
}

