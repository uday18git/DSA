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
bool hasPathSum(Node* root, int targetSum) {
        if (!root) {
            return false;
        }
    
        targetSum -= root->data;
    
        if (!root->left && !root->right) {
            return targetSum == 0;
            }
    
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right, targetSum);
        
}