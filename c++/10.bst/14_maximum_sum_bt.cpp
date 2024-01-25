// my brute force approach is to use the validate bst function 
// and if the bt is valid return its sum
#include <bits/stdc++.h> 
using namespace std;
struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right){}
};
bool validate(TreeNode* root,long long int mini,long long int maxi,int &currsum,int &maxsum)
{
    if(!root){currsum=0;return true};
    if(root->val >=maxi || root->val <=mini)return false;
    bool left = validate(root->left,mini,root->val);
    bool right = validate(root->right,root->val,maxi);
    return (left && right);
}
int main(){

return 0;
}