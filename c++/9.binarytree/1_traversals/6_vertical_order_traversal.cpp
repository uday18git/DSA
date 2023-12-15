//            level     using multiset because the value can be same for multiple nodes itseems
//multiset can store duplicate values also 
// map<int,map<int,multiset<int>>>
// vertical(-1,0,1) 
// queue<pair<int,pair<int,int>>>
//   stores  node  vertical level

#include <bits/stdc++.h> 
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* right;
    struct TreeNode* left;
    TreeNode(int data)
    {
        val=data;
        right=NULL;
        left=NULL;
    }
};

vector<vector<int>> vertical_order_traversal(TreeNode* root)
{
    //vertical  // level // each level nodes
    map<int,map<int,multiset<int>>> ds;
    queue<pair<TreeNode*,pair<int,int>>> q;
    vector<vector<int>> ans;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            auto x = q.front();
            q.pop();
            if(x.first)
            {
                int y = x.second.first;
                int z = x.second.second;
                ds[y][z].insert(x.first->val);
                if(x.first->left)
                {
                    q.push({root->left,{y-1,z+1}});
                }
                if(x.first->right)
                {
                    q.push({root->right,{y+1,z+1}});
                }
            }
        }
    }
    for(auto it=ds.begin();it!=ds.end();++it)
    {
        vector<int> a;
        for(auto it1=it->second.begin();it1!=it->second.end();++it1)
        {
            a.push_back()
        }
    }
// work left here

}

int main(){

return 0;
}