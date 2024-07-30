// https://leetcode.com/problems/create-binary-tree-from-descriptions/


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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int, bool> hasParent;

        for(auto description:descriptions)
        {
            int parent = description[0],child = description[1],isLeft= description[2];
            TreeNode* parentNode =  NULL,*childNode = NULL;
            if(mp.find(parent)!=mp.end())parentNode = mp[parent];
            else{ parentNode = new TreeNode(parent); mp[parent]=parentNode;}

            if(mp.find(child)!=mp.end())childNode = mp[child];
            else{ childNode = new TreeNode(child);mp[child]=childNode;}

            if(!isLeft)parentNode->right=childNode;
            else parentNode->left = childNode;
            hasParent[child]=true;
        }
        TreeNode* root = NULL;
        for(auto it:mp)   
        {
            if(!hasParent[it.first])root=it.second;
        }
        return root;
    }
};