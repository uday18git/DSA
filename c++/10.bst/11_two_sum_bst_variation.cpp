// brute force is to get the inorder
// and put two pointers at start and end of the inorder array 
// as it is sorted array , we can find the sum by moving the pointers
// we take the sum of the first and last if the sum is greater than the required sum then we move the end pointer to left
// if the sum is lesser than the required sum then we move the start pointer to right
// tc is O(n) and sc is O(n)

// my brute force implementation is dynamic

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
 * 
 * 
 */
class Solution {
public:
    void inorder(TreeNode* root,int k,bool &ans,map<int,bool>&mp)
    {
        if(!root)return;
        inorder(root->left,k,ans,mp);
        mp[root->val]=true;
        if(mp.find(k-root->val)!=mp.end() && k-root->val != root->val)ans=true;
        inorder(root->right,k,ans,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans=false;
        map<int,bool>mp;
        inorder(root,k,ans,mp);
        return ans;
    }
};
// better approach 

// we willl use the concept of bst iterator
// bst iterator next and before we will use those 
// so space complexity here will be O(H)*2 = O(H) and time complexity will be O(1) for next and hasnext
// same as above written approach but we will use this next and before 

class Solution {
public:
    stack<TreeNode*>n;
    stack<TreeNode*>b;
    int next()
    {
        TreeNode* temp = n.top();
        n.pop();
        pushLeft(temp->right);
        return temp->val;
    }
    int before()
    {
        TreeNode* temp = b.top();
        b.pop();
        pushRight(temp->left);
        return temp->val;
    }
    void pushLeft(TreeNode* subject)
    {
        for(;subject;n.push(subject),subject=subject->left);
    }
    void pushRight(TreeNode* subject)
    {
        for(;subject;b.push(subject),subject=subject->right);
    }

    bool findTarget(TreeNode* root, int k) {
        pushLeft(root);
        pushRight(root);
        int i=next();
        int j=before();
        while(i<j)
        {
            if(i+j == k)return true;
            else if(i+j < k)i=next();
            else j=before();
        }
        return false;
    }
};
