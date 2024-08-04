//  striver
// used in lca

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        left = NULL;
        right = NULL;
        val = data;
    }
};
bool path(TreeNode* root, TreeNode* node, vector<int>& arr) {
    if(root==NULL)return false;
    arr.push_back(root->val);
    if(root->val==node->val)return true;
    bool left = path(root->left,node,arr);
    bool right = path(root->right,node,arr);
    if(!left && !right)
    {
        arr.pop_back();
    }
    return (left || right);
}

int main() {
    // Create the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // Find the path for node 4
    TreeNode* node = root->right->right;
    vector<int> pathArr;
    bool found = path(root, node, pathArr);
    // Print the modified array
    for (int i = 0; i < pathArr.size(); i++) {
        cout << pathArr[i] << " ";
    }
    cout << endl;
    return 0;
}



// path to all leaf nodes
// can do without backtracking also which is easier to do 
void solve(Node* root, vector<int>& curr, vector<vector<int>>& ans) {
    if (!root) return;

    // Add the current node's data to the current path
    curr.push_back(root->data);

    // If the current node is a leaf, add the path to the answer
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(curr);
    } else {
        // Recur for left and right subtrees
        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }

    // Backtrack: remove the current node's data from the current path
    curr.pop_back();
}

vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(root, curr, ans);
    return ans;
}
