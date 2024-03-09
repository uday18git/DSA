// apna clg

// #include "bits/stdc++.h" 
// using namespace std;
// apna college
//MAX PATH SUM --- TO FIND THE MAX SUM THROUGH A PATH
//STRATEGY ---> FOR EACH NODE WE WILL COMPUTE 4 VALUES THEN COMPARE THIS WITH A GLOBAL VARIABLE MAX SUM THEN MAX VALUE WE TAKE
//1. NODE VAL
//2. MAX PATH THROUGH LEFT CHILD+NODE VAL
//3. MAX PATH THROUGH RIGHT CHILD + NODE VAL
//4. MAX PATH THROUGH LEFT CHILD + RIGHT CHILD + NODE VAL 
// WE WILL START WITH LEAF NODE
#include <iostream>
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
int PathSum(Node *root,int &ans)
{
    if(!root)return 0;
    int left = PathSum(root->left,ans);
    int right = PathSum(root->right,ans);
    int nodeMax = max(max(root->data,root->data+left+right),
                    max(root->data+right,root->data+left));
    ans=max(nodeMax,ans);
    int singlePathSum = max(root->data,max(root->data+right,root->data+left)); // here we are ignoring the root->data + left+ right because we that itself will be a complete path and you cant add the ancestors here
    return singlePathSum;

}
int maxPathSum(Node* root)
{
    int ans = INT_MIN;
    PathSum(root,ans);
    return ans;
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(5);
    root->right->right = new Node(5);
    cout<<maxPathSum(root)<<endl;
    return 0;
}