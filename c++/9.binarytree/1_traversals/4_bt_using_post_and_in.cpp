// using postorder and inorder
// same as preorder and inorder we have to start from the back
// and we have to build right first
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
int search(int inorder[], int start, int end, int val)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}
// inorder's staart and end
Node *buildTree(int postorder[], int inorder[], int start, int end)
{

    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }
    int val = postorder[idx]; // initially we take the first element of preorder which is root basically
    idx--;
    Node* curr = new Node(val);
    // we have to find where this curr is in the inorder
    if (start == end)
    {
        return curr;
    }
    int pos = search(inorder, start, end, val);
    curr->right = buildTree(postorder, inorder, pos + 1, end);//****************
    curr->left = buildTree(postorder, inorder, start, pos - 1); // first we will build the left subtree of the root
    // position is where we find the root node so we take till pos-1 above
    

    return curr;
}
void inorderPrint(Node *root)
{

    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
int main()
{
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);
}