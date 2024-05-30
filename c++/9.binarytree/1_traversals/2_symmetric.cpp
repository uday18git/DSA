// symmetrical binary tree
// if u draw a line below the root , left should be mirror of right

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

// VERY SIMILAR TO THE PREVIOUS IS SAME QUESTION JUST FLIPPIT

class Solution
{
public:
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        bool left = isSame(p->left, q->right);
        bool right = isSame(p->right, q->left);
        return left && right;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSame(root->left, root->right);
    }
};

