// we use queue to do level order traversal
// first we insert root null
// 1 NULL
// remove elements from queue one by one
// remove 1 then insert left child then insert right child
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


// algorithm is 
// initally put root and null into the q
// then till queue is not empty
// take the front element
// pop it from the queue
// if the element is not null
// add its left and right element to the queue 
// if the element is null 
// check if queue is empty , if its empty stop the queue
// if its not emmpty some more levels are tehre so pusback null
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


// SHORT NOTES
// we solve this using q
// in q we push root and null
// it reaches null means one level is done
// while(!q.empty())
// we have to take the front node of the q and pop it
// and if the node is not empty print it and push its left and right if they exist
// then check if the q is empty because we popped a element above
// if the q is not empty push null because one level is done

// The time and space complexity of the level order traversal of a binary tree depends on the number of nodes in the tree.

// Let's denote the number of nodes in the binary tree as "n."

// Time Complexity: O(n)

// Each node is visited exactly once during the level order traversal.
// The time complexity is linear, O(n), where "n" is the number of nodes in the binary tree.
// Space Complexity: O(w)

// The space complexity of level order traversal is determined by the maximum number of nodes at
//  any level in the tree, which is the width of the widest level.
// In the worst case, the maximum width of the tree is the number of nodes at the last level, which can
//  be at most n/2 in a complete binary tree.
// Therefore, the space complexity is O(w), where "w" is the maximum width of the tree.
// In the worst case, for a completely unbalanced tree, the maximum width could be equal to the 
// number of nodes at the lowest level, which may lead to a space complexity of O(n). However, for a balanced binary tree, 
// the maximum width is limited to approximately n/2, resulting in a space complexity of O(n/2) or simply O(n) for big-O notation.





