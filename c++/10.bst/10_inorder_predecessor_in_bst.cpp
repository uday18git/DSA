// to find the inorder succesor/ predecessor 
// there are 3 methods
// first is to traverse and store the inorder and to find it , tc and sc involved is O(n) and O(n), extreme brute force this is
// we can do better , first value that we encounter greater than the given node is the inorder succesor , this approach is O(n) and O(1)
// efficient approach , we store a variable named successor, initially =null , we traverse the tree if , so we start from the root , so if the root is lesser than the given node we go to the right subtree to find the successor, till we get >= the given node so when we get it we update successor value, then we go left then repeat the same process
//               5
//             /   \
//            2     7
//           / \   / \
//          1   4 6   9
//             /     / \
//            3     8   10
// consider example val=3 and 8
// for successor
/// approach is to so key value is there now compare key value iwth root , if it is less than root then go to left side and it will be a possible solution so store it then compare again, if it is greater then
#include <bits/stdc++.h> 
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
    TreeNode(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};
class Solution{
    public:
        TreeNode* inorderSuccessor(TreeNode* root,TreeNode* p)
        {
            TreeNode* successor = NULL;
            while(root != NULL)
            {
                if(p->val >=root->val)
                {
                    root = root->right;
                }
                else
                {
                    successor = root;
                    root = root->left;
                }
            }
            return successor;
        }
};
// predecessor code
class Solution{
    public:
        TreeNode* inorderPredecessor(TreeNode* root,TreeNode* p)
        {
            TreeNode* predecessor = NULL;
            while(root != NULL)
            {
                if(p->val <= root->val)
                {
                    root = root->left;
                }
                else
                {
                    predecessor = root;
                    root = root->right;
                }
            }
            return predecessor;
        }
};


// pre and suc both in one code given below
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        // first lets find the pre then post
        Node* temp=root;
        while(temp!=NULL)
        {
            if(key<=temp->key)
            {
                temp=temp->left;
            }
            else
            {
                pre=temp;
                temp=temp->right;
            }
        }
        while(root!=NULL)
        {
            if(key>=root->key)
            {
                root=root->right;
            }
            else
            {
                suc = root;
                root=root->left;
            }
        }
    }
};