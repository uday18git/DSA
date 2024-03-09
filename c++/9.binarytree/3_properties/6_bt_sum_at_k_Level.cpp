// apna clg

// APPLICATION OF LEVEL ORDER TRAVERSAL
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
void sumatKLevel(Node* root,int k){
    int level=0,sum_at_k=0;
    if(root == NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);//first we insert root null
    q.push(NULL);
    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        if(node != NULL)
        {
            if(level==k)
            {
                // cout<<node->data<<" ";
                sum_at_k+=node->data;
            }
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())//this is if node==null so here we have traversed a level whatever level it is and we removed null //if it is not empty push null to the back if it is empty it will automatically terminate
        {
            level++;
            q.push(NULL);
        }
    }
    cout<<"The sum at level "<<k<<" is "<<sum_at_k<<endl;
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
    sumatKLevel(root,0);
    return 0;
}