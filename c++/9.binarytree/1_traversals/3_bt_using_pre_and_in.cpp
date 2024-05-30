// APNA COLLEGE
// using preorder and inorder
// algo
// 1. Pick element from preorder and create a node.
// 2. Increment preorder idx, we will iterate through preorder
// 3. Search for picked elements pos in inorder
// 4. call to build left subtree from inorder's 0 to pos-1
// 5. call to build right subtree from inorder pos+1 to n
// 6. Return the node.
// first we have to build left then right
#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
// int search(int inorder[], int start, int end, int curr)
// {
//     for (int i = start; i <= end; i++)
//     {
//         if (inorder[i] == curr)
//         {
//             return i;
//         }
//     }
//     return -1;//this will never come
// }
// // inorder's start and end
// Node *buildTree(int preorder[], int inorder[], int start, int end)
// {
//     static int idx = 0;
//     if (start > end)
//     {
//         return NULL;
//     }
//     int curr = preorder[idx]; // initially we take the first element of preorder which is root basically
//     idx++;
//     Node *node = new Node(curr);
//     // we have to find where this curr is in the inorder
//     if (start == end)//if there is only 1 element
//     {
//         return node;
//     }
//     int pos = search(inorder, start, end, curr);
//     node->left = buildTree(preorder, inorder, start, pos - 1); // first we will build the left subtree of the root
//     // position is where we find the root node in inorder so we take till pos-1 above
//     node->right = buildTree(preorder, inorder, pos + 1, end);
//     return node;
// }
// void inorderPrint(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     inorderPrint(root->left);
//     cout << root->data << " ";
//     inorderPrint(root->right);
// }
// int main()
// {
//     int preorder[] = {1, 2, 4,3, 5};
//     int inorder[] = {4, 2, 1, 5, 3};
//     Node *root = buildTree(preorder, inorder, 0, 4);
//     inorderPrint(root);
// }

// you can also use map to mimic this function
// where key is the element and value is the index
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
} // whole calculation is going on on the inorder array start and end , and idx is the one traversing on preorder array
Node *buildtree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int idx = 0;
    int curr = preorder[idx];
    Node *node = new Node(curr);
    idx++;
    // if there is only one element in the current array then there is no need to calculate nodes right and left
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildtree(preorder, inorder, start, pos - 1);
    node->right = buildtree(preorder, inorder, pos + 1, end);
    return node;
}

void inorderprint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout << root->data;
    inorderprint(root->right);
}
int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildtree(preorder, inorder, 0, 4);
    inorderprint(root);
    return 0;
}

Node *buildtree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
        return NULL;
    static int idx = 0;
    int curr = preorder[idx];
    Node *node = new Node(curr);
    idx++;
    if (start == end)
        return node;
    int pos = search(inorder, start, end, curr); // searches for the element in inorder in the current range
    node->left = buildtree(preorder, inorder, 0, pos - 1);
    node->right = buildtree(preorder, inorder, pos + 1, end);
    return node;
}




// passed in leet code

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>inorder,int start,int end,int curr)
    {
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==curr)return i;
        }
        return 0;
    }
    TreeNode* build(vector<int>preorder,vector<int>inorder,int start,int end,int &idx)
    {
        if(start>end)return NULL;
        int curr = preorder[idx];
        idx++;
        TreeNode* node= new TreeNode(curr);
        if(start==end)return node;
        int pos = search(inorder,start,end,curr);
        node->left = build(preorder,inorder,start,pos-1,idx);
        node->right = build(preorder,inorder,pos+1,end,idx);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        return build(preorder,inorder,0,preorder.size()-1,idx);
    }
};

