 // https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
 // first way to do is , using LCA , after finding the lca for start and dest.....
 // find path of start and dest from the lca , and from start to lca it will be u u u 
 // and from lca to dest it will be l r  .. whatever
class Solution {
public:
    TreeNode* lca(TreeNode* node,int p,int q)
    {
        if(node==NULL)return node;
        TreeNode* left = lca(node->left,p,q);
        TreeNode* right = lca(node->right,p,q);
        if((left && right) || (node->val == p) || (node->val==q))
        {
            return node;
        }
        return (left==NULL)?right:left;
    }
    string lcaToStart , lcaToEnd;
    void dfs(TreeNode* node,string& pathString,int p,int q)
    {
        if(node==NULL)return;
        if(node->val ==p )lcaToStart = pathString;
        if(node->val ==q )lcaToEnd = pathString;
        pathString.push_back('L');
        dfs(node->left,pathString,p,q);
        pathString.pop_back();
        pathString.push_back('R');
        dfs(node->right,pathString,p,q);
        pathString.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode = lca(root,startValue,destValue);
        string pathString ="";
        dfs(lcaNode,pathString,startValue,destValue);
        for(auto& ch:lcaToStart)ch='U';
        return lcaToStart + lcaToEnd;
    }
};



 // another way is to not using LCA so we can , 
 // grab the paths of both start and dest from the root then....
 // the common part will be th lca and we have to 
class Solution {
public:
   
    string rootToStart , rootToEnd;
    void dfs(TreeNode* node,string& pathString,int p,int q)
    {
        if(node==NULL)return;
        if(node->val == p)rootToStart = pathString;
        if(node->val == q)rootToEnd = pathString;
        pathString.push_back('L');
        dfs(node->left,pathString,p,q);
        pathString.pop_back();

        pathString.push_back('R');
        dfs(node->right,pathString,p,q);
        pathString.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathString ="";
        dfs(root,pathString,startValue,destValue);
        int i=0,j=0,commonLen=0;
        while(i<rootToStart.length() && j<rootToEnd.length())
        {
            if(rootToStart[i] ==rootToEnd[j] )
            {
                commonLen++;
                i++;
                j++;
            }
            else
            {
                break;
            }
        }
        rootToStart = rootToStart.substr(commonLen,rootToStart.length()-commonLen);
        rootToEnd = rootToEnd.substr(commonLen,rootToEnd.length()-commonLen);

        for(auto& ch:rootToStart)ch='U';
        return rootToStart + rootToEnd;
    }
};