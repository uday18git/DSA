//SORTED ARRAY TO A HEIGHT BALANCED BST .. HEIGHT DIFFERNCE BETWEEN SUBTREE IS <=1
//sorted array [1,2,3]
#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node* right,*left;
    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }

};
//MAKE MIDDLE ELEMENT ROOT
//RECURSIVELY FORM SUBTREES
//START TO MID-1 =>LEFT SUBTREE
//MID+1 TO END =>RIGHT SUBTREE

Node* sortedArrToBST(int arr[],int start,int end)
{
    if(start>end)return NULL;
    int mid = (start+end)/2;
    Node* node = new Node(arr[mid]);
    node->left= sortedArrToBST(arr,start,mid-1); 
    node->right= sortedArrToBST(arr,mid+1,end); 
    return node;
}
void preorderPrint(Node* root)
{
    if(!root)return;
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
int main()
{
    int arr[] = {10,20,30,40,50};
    Node* root=sortedArrToBST(arr,0,4);
    preorderPrint(root);
    return 0;
}