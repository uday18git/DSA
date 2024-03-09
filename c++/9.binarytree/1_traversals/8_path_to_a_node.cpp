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
    if (root == NULL) {
        // arr.pop_back(); not here because it will pop 2 times for nodes where left and right are NULL but we need to pop only once
        return false;
    }
    arr.push_back(root->val);
    if (root->val == node->val) {
        return true;
    }
    bool left = path(root->left, node, arr);
    bool right = path(root->right, node, arr);
    if(!left && !right) {
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
    TreeNode* node = root->left->right;
    vector<int> pathArr;
    bool found = path(root, node, pathArr);
    // Print the modified array
    for (int i = 0; i < pathArr.size(); i++) {
        cout << pathArr[i] << " ";
    }
    cout << endl;
    return 0;
}

