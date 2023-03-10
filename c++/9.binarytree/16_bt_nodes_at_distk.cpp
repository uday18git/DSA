//to find distance at distance k from a specific node it can either be through subtree of the node or from the ancestor 
//first case(subtree) we will take k=number then keep decrementing k till k is 0 in the subtree of the node
//second case(ancestor) 1.find the distance(d) of all ancestors from target node ... for all ancestors find the node using k-d ... if node is in the left subtree of ancestor we will search in right subtree
// so the second case is reduced into first case 
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
void printSubtreeNodes(Node * root,int k)//to print in the subtree itself      
{
    if(!root || k<0)return;
    if(!k){cout<<root->data<<" ";return;}
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}
//case 2.. if we get the target node then we will return the distance from target to ancestor
int printNodesAtk(Node* root,Node *target,int k)
{
    if(root==NULL)//if we do not get the target
    {
        return -1;
    }
    if(root==target)//if we get the 
    {
        printSubtreeNodes(root,k);
        return 0;
    }//we did not get target yet, to find target so we'll first try to find in leftsubtree
    int dl = printNodesAtk(root->left,target,k);//dl is the distance from root to target
    if(dl!=-1){ //means that we have found our target in the left subtree
        if(dl+1==k)//means ancestor is only k distance from target therefore we print the ancestor's data
        {
            cout<<root->data<<" ";
        }else//in the else case we will try to find dist k nodes in the right subtree of the root
        {
            printSubtreeNodes(root->right,k-dl-2);// we are calling it on roots right so there 1 extra and 
        }
        return 1+dl;
    }
    int dr = printNodesAtk(root->right,target,k);//dr is the 
    if(dr!=-1){ //means that we have found our target in the left subtree
        if(dr+1==k)//means ancestor is only k distance from target therefore we print the ancestor's data
        {
            cout<<root->data<<" ";
        }else//in the else case we will try to find dist k nodes in the right subtree of the root
        {
            printSubtreeNodes(root->left,k-dl-2);// we are calling it on roots right so there 1 extra and 
        }
        return 1+dr;
    }
    return -1;
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
    printNodesAtk(root,root,2);
    return 0;
}