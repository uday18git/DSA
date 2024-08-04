// properties of binary trees
// 1.maximum nodes at level L = 2^L
// 2.maximum nodes in a level of height H is 2^H -1
// 3.For n nodes minimum heigth is log2(n+1)
// 4.A bt has L leaves then it has at least log2(N+1)+1 number of levels

#include <iostream>
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
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return 0;
}