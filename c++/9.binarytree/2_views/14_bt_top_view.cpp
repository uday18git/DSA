//striver

// top view of bt
#include <bits/stdc++.h> 
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};

void top_view(TreeNode* root)
{
    queue<pair<TreeNode* ,int>>q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            auto x=q.front();
            q.pop();
            if(x.first)
            {
                if(m.find(x.second)==m.end())
                {
                    m[x.second]=x.first->val;
                }
                if(x.first->left)
                {
                    q.push({x.first->left,x.second-1});
                }
                if(x.first->right)
                {
                    q.push({x.first->right,x.second+1});
                }
            }
        }
    }
    for(auto it=m.begin();it!=m.end();++it)
    {
        cout<<it->second<<" ";
    }
}
int main(){
    TreeNode* node = new TreeNode(1);
    node->right=new TreeNode(3);
    node->left->left=new TreeNode(4);
    node->left->right=new TreeNode(5);
    node->left=new TreeNode(2);
    node->right->left=new TreeNode(6);
    node->right->right=new TreeNode(7);
    top_view(node);
return 0;
}

// tc o(n)
// sc o(n)
// where n is the number of nodes in the binary tree