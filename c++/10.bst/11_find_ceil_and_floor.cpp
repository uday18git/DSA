#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int ans;
    // Write your code here.
    while(root)
    {
        if(root->val>X)
        {
            root=root->left;
        }
        else if(root->val==X)
        {
            return root->val;
        }
        else
        {
            ans=root->val;
            root=root->right;   
        }
    }
    return ans;
}


#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans=INT_MAX;
    while(node)
    {
        if (node->data >= x) {
            ans = node->data;
            node = node->left;
        } 
        // If the current node's data is less than x, move to the right subtree
        else {
            node = node->right;
        }

    }
    return ans==INT_MAX?-1:ans;
}