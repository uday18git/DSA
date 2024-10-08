// striver or ac

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
// we use level order traversal
void right_view(Node* root)
{
    if(!root)return; // important dont forget
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr = q.front();
            q.pop();
            // cout<<curr->data<<" ";  level order traversal it shd give
            if(i==n-1)
            {
                cout<<curr->data<<" ";
            }
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }

    }
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
    right_view(root);
    return 0;
}
//same level order traversal we use for loop
// and we take the n-1 the node in each level