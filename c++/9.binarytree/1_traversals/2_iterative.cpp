#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* right;
        Node* left;
        Node(int val)
        {
            data=val;
            left=NULL;
            right=NULL;
        }
};

// iterative preorder same as level order traversal

// root left right

int main()
{
    Node* root= new Node(1);
    root->right= new Node(3);
    root->left= new Node(2);
    root->left->left= new Node(4);
    root->left->left->left= new Node(5);
    stack<Node*>s;
    s.push(root);
    while(!s.empty())
    {
        Node* node = s.top();
        s.pop();
        if(node)
        {
            cout<<node->data<<" ";
            if(node->right)
            {
                s.push(node->right);
            }
            if(node->left)
            {
                s.push(node->left);
            }
        }
    }

    vector<int> inorder;
    Node* node=root;
    while(true)
    {
        if(node!=NULL)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            if(s.empty() == true)break;
            node = s.top();
            s.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    for(int i:inorder)
    {
        cout<<i<<" ";
    }
    return 0;

}