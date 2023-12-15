// bottom view
//            1
//          /   \
//         2     3
//        / \    / \   
//       4   5  6   7   
// here if we see from botttom u have to take the right one (6)
// if we do vertical order traversal it is nothing but the last node of each vertical line

#include <bits/stdc++.h> 
using namespace std;
struct TreeNode{
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
void bottom_view(TreeNode* root)
{
    queue<pair<TreeNode*,int>> q;
    map<int,int> m;
    q.push({root,0});
    while(!q.empty())
    {
        
        
        auto x = q.front();
        q.pop();
        
        m[x.second] = x.first->val;
        if(x.first->left)
        {
            q.push({x.first->left,x.second-1});
        }
        if(x.first->right)
        {
            q.push({x.first->right,x.second+1});
        }
        
        
        
    }
    for(auto it=m.begin();it!=m.end();++it)
    {
        cout<<it->second<<" ";
    }
}
int main(){
    TreeNode* node = new TreeNode(1);
    node->left=new TreeNode(2);
    node->left->left=new TreeNode(4);
    node->left->right=new TreeNode(5);
    node->right=new TreeNode(3);
    node->right->left=new TreeNode(6);
    node->right->right=new TreeNode(7);
    bottom_view(node);
return 0;
}

// i donno why level order traversal they have not done ,,, something lil different they have done
// recursive traversal is not possible

// sc = O(n)
// tc = O(n)
// where n is the number of nodes in the tree