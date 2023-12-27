#include "bits/stdc++.h"
using namespace std;
struct Node{
    int data;
    Node* left,*right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
// we can build bst using preorder .. we already know inorder of a bst
// WE WILL BE GIVEN PREORDER SEQUENCE .. WE WILL MAINTAIN MIN AND MAX 
// 7 5 4 6 8 9
// FOR 7 MIN MAX IS NULL NULL
// FOR 7'S LEFT CHILD MAX IS 7(because in bst left tree cannot have a number greater than its root) MINN IS NULL  key is current value that we are building. n is total number of eleemnts.
Node* constructBST(int preorder[],int* preorderIdx,int key,int min,int max,int n)
{
    if(*preorderIdx>=n){return NULL;}
    Node* root = NULL;
    if(key>min && key<max){
        root = new Node(key);
        //here we have to update out preorder idx because we have made node for our current key
        *preorderIdx=*preorderIdx+1;
        if(*preorderIdx < n){
            root->left = constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            root->right = constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;//we return null id not satisying conditions
}
void printPreorder(Node* root)
{
    if(!root)return;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main()
{
    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int preorderIdx = 0;
    
    Node* root = constructBST(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    printPreorder(root);
    return 0;
}