// striver

//            level     using multiset because the value can be same for multiple nodes itseems
// multiset can store duplicate values also
// map<int,map<int,multiset<int>>>
// vertical(-1,0,1)
// queue<pair<int,pair<int,int>>>
//   stores  node  vertical level
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *right;
    struct TreeNode *left;
    TreeNode(int data)
    {
        val = data;
        right = NULL;
        left = NULL;
    }
};

vector<vector<int>> vertical_order_traversal(TreeNode *root)
{
    // vertical  // level // each level nodes
    // we need to store level also because we have to maintain the order up to down
    map<int, map<int, multiset<int>>> ds;
    queue<pair<TreeNode *, pair<int, int>>> q;
    vector<vector<int>> ans;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto x = q.front();
            q.pop();
            if(x.first)
            {    
                int y = x.second.first;
                int z = x.second.second;
                ds[y][z].insert(x.first->val);
                if (x.first->left)
                {
                    q.push({x.first->left, {y - 1, z + 1}});
                }
                if (x.first->right)
                {
                    q.push({x.first->right, {y + 1, z + 1}});
                }
            }
        }
    }
    for (auto it : ds)
    {
        vector<int> a;
        for (auto it1 : it.second)
        {
            for(auto it2:it1.second)
            {
                a.push_back(it2);
            }
        }
        ans.push_back(a);
    }
    
    // can do as below also
    // for(auto it=mp.begin();it!=mp.end();++it)
    //     {
    //         multiset<int> s = it->second;
    //         vector<int>v(s.begin(),s.end());
    //         ans.push_back(v);
    //     }
    return ans;
    // work left here
}

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    // root->left->left->right = new TreeNode(5);
    // root->left->left->right->right = new TreeNode(6);
    // root->right = new TreeNode(3);
    // root->right->left = new TreeNode(9);
    // root->right->right = new TreeNode(10);

    vector<vector<int>> verticalTraversal;
    verticalTraversal = vertical_order_traversal(root);

    cout << "The Vertical Traversal is : " << endl;
    for (auto vertical : verticalTraversal)
    {
        for (auto nodeVal : vertical)
        {
            cout << nodeVal << " ";
        }
        cout << endl;
    }
    return 0;
}