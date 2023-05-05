//for each node 5 points of info we shd store
//1- min value of the subtree including the node
//2- max value fo the subtree including the node
//3- subtree size --> means including that node what is the size of the subtree
//4- size of largest BST 
//5- isBST for any node is the node part of a mini bst 
// RECURSIVELY TRAVERSE IN A BOTTOM UP MANNER 
#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    Node* left,*right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root)
{
    if(!root)return {0,INT_MIN,INT_MAX,0,true};
    if(!root->right&&!root->left)return {1,root->data,root->data,1,true};
    Info leftInfo = largestBSTinBT(root->left);
    Info rightInfo = largestBSTinBT(root->right);
    Info curr;
    curr.size = 1+leftInfo.size+rightInfo.size;
    if(leftInfo.isBST&&rightInfo.isBST && leftInfo.max < root->data&& rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min,min(rightInfo.min,root->data));
        curr.max = max(leftInfo.max,max(rightInfo.max,root->data));
        curr.ans = curr.size;//because we are coming from bottom 
        curr.isBST =true;
        return curr;
    }
    curr.ans = max(leftInfo.ans,rightInfo.ans);
    curr.isBST = false;
    return curr;


}
int main()
{
    struct Node* root1 = new Node(15);
    root1->left = new Node(20);
    root1->right = new Node(30);
    root1->left->left = new Node(5);
    // root1->left->right = new Node(5);
    // root1->right->left = new Node(6);
    // root1->right->right = new Node(7);
    cout<<"LARGST BST:"<<largestBSTinBT(root1).ans<<endl;
}