// BST ITERATOR
// next
// has
// hasnext
// straight forward approach will be to take inorder of the tree
// then use the iterator to get the next element or check if next is there 

// but this will take O(n) space and O(n) time

// required is O(H) space 
// Tc O(1) for next and hasnext

// we will use stack to store the elements
// so if BSTiterator(root) is called
// store all the left elements to the stack
// then if next is called pop the top element then store the right and its left left left elements to the stack
// if hasnext is called check if stack is empty or not , if its empty has next returns false

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h> 
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right){}
};
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushLeft(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return (!s.empty());
    }
    void pushLeft(TreeNode* subject)
    {
        for(;subject;s.push(subject),subject=subject->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// the above is implementation for bst next
// how to do bst before
// code

// before will be exactly opposite of next
// exactly opposite