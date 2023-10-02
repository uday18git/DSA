//height of a binary tree is the deepest node to root 
//recursively we'll find out the height of every node first remove height to left subtree and right subtree finally we will add one to the max of those

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
//time complexity O(N) where n is number of nodes
int Height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int lheight = Height(root->left);
    int rheight = Height(root->right);
    return max(lheight,rheight)+1;

}
//diameter is the number of nodes in the longest path between any 2 leaves!!
//it can go through root or no
//strategy we will remove the diameter of left subtree and right subtree and left and right ka height bhi nikaal lenge
//if our diameter is passing through current node then it is height of left subtree + right subtree + 1 or else max(left dia,right dia) we will do this recursively
//diameter time complexity is O(N^2)
int Diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight= Height(root->left); 
    int rheight= Height(root->right);
    int currDiameter = lheight+rheight+1;
    int lDia = Diameter(root->left);
    int rDia = Diameter(root->right);
    return max(currDiameter,max(lDia,rDia)); 
}
//OPTIMISED DIAMETER WE WILL TAKE A POINTER OF HEIGHT PASS IN SAME RECURSIVE FUNCTION SO OUR TIME COMP DECREASES TO O(N)
int OptDiameter(Node *root,int* height)
{
    if(root==NULL)
    {
        *height = 0;
        return 0;
    }
    int lh=0,rh=0;
    int lDia = OptDiameter(root->left,&lh);
    int rDia = OptDiameter(root->right,&rh);
    int currDiameter = lh+rh+1;
    *height = max(lh,rh)+1;
    return max(currDiameter,max(lDia,rDia));//currdiameter when root is included, max(lDia,rDia) if not passing from root

}
int main()
{
    int height= 0;
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<Diameter(root)<<endl;
    return 0;
}