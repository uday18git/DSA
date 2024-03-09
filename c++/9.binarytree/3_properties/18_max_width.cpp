// max width of a binary tree
// we will use level order traversal
// and mark each node as 0 is root , 1 is left child , 2 is right child like that
// mark each node with the formula 2*index+1 and 2*index+2
// and then we will find the max difference between the first and last index of each level

// /**
//  * Definition for a binary tree node.

// VERY GOOD QUESTION WITH MULTIPLE LESSONS
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        int ans = 0;
        long long currmin, currmax;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto curr = q.front();
                TreeNode *node = curr.first;
                long long val = curr.second;
                q.pop();
                if (i == 0)
                {
                    currmin = val;
                }
                if (i == n - 1)
                {
                    currmax = val;
                }
                if (node->left)
                {
                    // q.push({node->left,(val-currmin)*2+1}); // did not work
                    q.push({node->left, (val - currmin) * 2}); // did not work
                    // issue was that val and currmin were taking large values, individually , but subtracting them will give integer value, so we have to
                    // use long long for these intermediate variables and not worry about the answer being in long long where int is expected ,as after subtracting and other stuff finally answer will be in integer
                }
                if (node->right)
                {
                    // q.push({node->right,(val-currmin)*2+2}); // did not work
                    q.push({node->right, (val - currmin) * 2 + 1}); // did not work
                }
            }
            ans = max(ans, int(currmax - currmin + 1));
        }
        return ans;
    }
};
