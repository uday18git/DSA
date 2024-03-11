// check if two bts are same

class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(!p&&!q)return true;
       if(!p||!q)return false;
       if(p->val != q->val)return false;
       bool left = isSameTree(p->left,q->left);
       bool right = isSameTree(p->right,q->right);
       return left && right;
    }
};