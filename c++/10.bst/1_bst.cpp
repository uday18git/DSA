//rule 1 = in left subtree value should be lesser than the node
//rule 2 = in right subtree value should be greater than the node
//rule 3 = all the subtrees should be bst's itself
// no duplicate nodes
#include "bits/stdc++.h"
using namespace std;
struct Node{
    int data;
    Node *right,*left;
    Node(int val)
    {
        data= val;
        right = NULL;
        left = NULL;
    }
};
Node* insertBST(Node* root,int val){
    if(!root)
    {
        return new Node(val);
    }
    if(val<root->data)
    {
        root->left=insertBST(root->left,val);
    }
    else
    {
        root->right=insertBST(root->right,val);
    }
    return root;
}
//IN A BINARY TREE TO SEARCH O(N)
//IN A BINARY SEARCH TREE O(LOG N)
Node* searchInBST(Node* root,int key){
    if(!root)return NULL;
    if(root->data==key)return root;
    if(root->data>key)return searchInBST(root->left,key);
    else return searchInBST(root->right,key);
}
//CASE 1 -> LEAF NODE - SIMPLY DELETE
//CASE 2 -> NODE HAS ONE CHILD .. REPLACE THE NODE WITH THE CHILD AND DELETE THE NODE 
//CASE 3 -> NODE HAS TWO CHILDREN 
// step 1 -> find the inorder successor of the node
// step 2 -> replace the node with its inorder successor
// step 3 -> delete the node
Node* inorderSucc(Node* root)
{
    Node* curr = root;
    while(curr && curr->left)
    {
        curr=curr->left;
    }
    return curr;
}
Node* DeleteInBST(Node* root,int key)
{
    if(key<root->data)
    {
        root->left=DeleteInBST(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=DeleteInBST(root->right,key);
    }
    else
    {
        if(!root->left){Node* temp=root->right;delete root;return temp;}
        else if(!root->right){Node* temp= root->left;delete root;return temp;}  
        //case 3
        Node* temp = inorderSucc(root->right);      
        root->data = temp->data;
        root->right = DeleteInBST(root->right,temp->data);//if there is a node following the node's right we want to delete
    }
    return root;

}
void inorder(Node* root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    Node* root=new Node(5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    // inorder(root);
    // if(!searchInBST(root,15))cout<<"key not there"<<endl;
    // else cout<< searchInBST(root,15)->data<<" key exists"<<endl;
    //BINARY SEARCH TREE ALWAYS GIVES A SORTED ARRAY
    //NICE
    inorder(root);
    root = DeleteInBST(root,4);
    cout<<endl;
    inorder(root);
}