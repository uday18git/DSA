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
void left_view(Node* root)
{
    if(!root)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            Node* curr = q.front();
            q.pop();

            if(i==0)
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
    left_view(root);
    return 0;
}
// we take the 0th node in each level
// tc and sc same as level order
// tc O(n)number of nodes in the bt and sc O(w)