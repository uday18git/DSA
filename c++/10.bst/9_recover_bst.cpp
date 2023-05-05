// 2 NODES WILL BE SWAPPED OF A BST TASK IS TO RECOVER THE BST
//  WE WILL USE THE PROPERTY THAT INORDER OF A BST IF SORTED
// CASE1 IS THAT -->2 SWAPPED ELEMENTS ARE NOT ADJACENT THEY R FAR
// CASE2 IS THAT -->2 SWAPPED ELEMENTS ARE  ADJACENT THEY R NOT FAR
//  MAINTAIN 3 POINTERS FIRST LAST AND MID
//  FIRST -> PREVIOUS NODE OF WHERE 1ST NUMBER IS < PREVIOUS
//  MID->NUMBER WHERE 1ST NUMBER IS < PREVIOUS
//  LAST -> 2ND NODE WHERE NUMBER < PREVIOUS
//  {1,8,3,4,5,6,7,2} FIRST = 8 , MID=3,LAST=2
//  FOR CASE 1 -> SWAP FIRST AND LAST
//  LAST WILL BE =NULL AND FIRST FIRST , MID =FIRST+1
//  {1,2,4,3,5,6,7,8} FIRST = 4 MID= 3
// WELL SWAP FIRST AND MID
#include "bits/stdc++.h"
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (!root)
        return;
    calcPointers(root->left, first, mid, last, prev);

    if (*prev && root->data < (*prev)->data) // condtition is that root ka data should always >prev ka data
    {
        if (!*first) // if its being violated first  time
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}
void restoreBST(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    last = NULL;
    mid = NULL;
    prev = NULL;
    calcPointers(root, &first, &mid, &last, &prev);
    if (last)
        swap(&(first->data), &(last->data));
    if (!last)
        swap(&(first->data), &(mid->data));
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);
    // root->left=new Node(9);
    // root->left=new Node(9);
    inorder(root);
    cout << endl;
    restoreBST(root);
    inorder(root);
    return 0;
}