// all in one lol
// we will use stack to solve this
// stack will have (node,num)
// if num==1 preorder , then ++ num then push the left of the num
// if num==2 inorder , then ++num then push right
// if num==3 then its last time then directly take it to postorder no need to push and all because its the last time
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int data)
    {
        val = data;
        right = NULL;
        left = NULL;
    }
};
vector<vector<int>> allinone(TreeNode *root)
{
    vector<int> pre;
    vector<int> post;
    vector<int> in;
    vector<vector<int>> ans;
    stack<pair<TreeNode*,int>> s;
    s.push({root,1});// initially push root and 1
    while(!s.empty())
    {
        auto x = s.top();
        s.pop();
        int num = x.second;
        if(num==1)
        {
            pre.push_back(x.first->val);
            s.push({x.first,num+1});
            if(x.first->left)
            {
                s.push({x.first->left,1});
            }
        }
        if(num==2)
        {
            in.push_back(x.first->val);
            s.push({x.first,num+1});
            if(x.first->right)
            {
                s.push({x.first->right,1});
            }
        }
        if(num==3)
        {
            post.push_back(x.first->val);
        }

    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;


}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> ans = allinone(root);
    for(auto x:ans)
    {
        for(auto y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}