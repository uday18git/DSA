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
class Solution {
public:
    void inorder(TreeNode* root, int &cnt, int k, int &ans) {
        if (!root || cnt >= k) {
            return;
        }

        inorder(root->left, cnt, k, ans);

        cnt = cnt + 1;
        if (cnt == k) {
            ans = root->val;
            return;
        }

        inorder(root->right, cnt, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int cnt = 0;
        inorder(root, cnt, k, ans);
        return ans;
    }
};

 // easiest solution is to do inorder
// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int>&ans)
//     {
//         if(!root)return;
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> in;
//         inorder(root,in);
//         return in[k-1];
//     }
// };


// for kth largest the count should be n-k , n is the total number of nodes in the tree