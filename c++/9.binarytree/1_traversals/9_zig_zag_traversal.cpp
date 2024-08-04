// apna colg

// zig zag traversal is root node left to right next right to left and so on
//  3 step strategy to implement.
//  1.use 2 stacks - currentLevel and nextLevel
//  2.variable LeftToRight... if it is true then left to right we go
//  3.if LeftToRight is true .. push left child then right else push right child then left
//  consider
//       1
//       / \
//      2   3
//      \    \ 
//       4   5
//           /\
//          6  7
//  first currLEvel stack = 1
//  print it to ans [1]
//  Left to Right is true so first left child of 1 will be pushed to next level stack..
//  one level is traversed
//  stacks are reversed so now curr stack has 2 3
//  ltor is false
//  3 element is popped and printed
//  ltor is false so 3s right child will be added to nextLevel first then left child.. then 2 is popped and printed and right and left childs are added to next level stack..
//  level over
//  ltor =true
//  stacks reversed .. curr stack 5 4
//  pop from curr level stack ... 4 is popped
//  4's left child is added 6 then 7 in next level
//  5 also same 5 dont have children so nothing is addedd
//  ltor  =false
//  exchange stacks
//  pop 7 and 6 ans = [1,3,2,4,5,7,6]
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

void printZigZag(Node *root)
{
    if(!root)return;
    stack<Node *> currLevel;
    stack<Node *> nextLevel;
    bool leftToRight = true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node *temp = currLevel.top();
        currLevel.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (leftToRight)
            {
                if (temp->left)
                    nextLevel.push(temp->left);
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            else
            {   // right to left
                if (temp->right)
                    nextLevel.push(temp->right);
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty())
        {
            leftToRight=!leftToRight;
            swap(currLevel,nextLevel);
        }
    }
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    printZigZag(root);
    return 0;
}