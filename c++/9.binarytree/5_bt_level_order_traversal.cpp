//we use queue to do level order traversal
//first we insert root null
// 1 NULL
//remove elements from queue one by one
//remove 1 then insert left child then insert right child
// NULL 2 3
// 1 is printed
// if we remove the next element which is null this indicates that one level has been traveresed this is the next level
// so we put the null back again
// 2 3 null 
// 2 will be removed push 2's left and right child
// 3 null 4 5 
// 3 will be removed push 3's left and right child
// null 4 5 6 7
// now null will be removed indicates one level has been traversed and nul will be pushed back
// 4 5 6 7 null
// 4 does not have lc and rc , so we just print it, same till 7 , so this time when the null will be removed, queue will be empty
// exit
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
void printLevelOrder(Node* root){
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
            cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())//this is if node==null so here we have traversed a level whatever level it is and we removed null //if it is not empty push null to the back if it is empty it will automatically terminate
            q.push(NULL);
    }


}
int main()
{
    struct Node* root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    printLevelOrder(root);
    return 0;
}