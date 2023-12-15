//given BINARY TREE TO FLATTEN IT INTO A LINKED LIST IN PLACE .. 
// LEFT OF EACH NODE SHOULD BE NULL AND RIGHT SHOULD CONTAIN NEXT NODE IN PREORDER SEQUENCE
//WE SHOULD NOT USE ANY OTHER DATA STRUCTURE
// STEPS -->
// 1.RECURSIVELY FLATTEN OUR LEFT AND RIGHT SUBTREEES
// 2.STORE THE LEFT TAIL AND RIGHT TAIL IN 2 VARIABLES
// 3.STORE THE RIGHT SUBTREE IN TEMP AND MAKE THE LEFT SUBTREE AS RIGHT SUBTREE ... MOVE THE LEFT THING TO RIGHT
// 4.THEN ATTACH THE TEMP AT LEFT TAIL
// 5.RETURN RIGHT TAIL.. WHY?? WHEN WE ARE FLATTENING THE SUBTREES .. AT THAT TIME WE CAN USE RIGHT TAIL TO FLATTEN THE ROOT

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
void Flatten(Node* root)
{
    if(!root || (!root->left && !root->right))return;//indication that that part of tree or whole tree is flat
    if(root->left){
        Flatten(root->left);// we have to flatten the left side before we put it in the right side
        Node* temp = root->right;//storing it in temporary variable
        root->right = root->left;//we shifted it to right so we can do left as nulll now
        root->left = NULL;
        Node* t=root->right;
        while(t->right)//traversing till last of the left which has been shifted to right
        {
            t=t->right;
        }
        t->right=temp;//now we set the right of the last element to temp which was previously right
    }
    Flatten(root->right);//we flatten it if in case there are any left subtrees are remaining

}
void inorder(Node* root)
{
    if(!root){cout<<"null"<<" ";return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}
int main()
{
    struct Node* root = new Node(1);
    // root->left = new Node(2);
    root->right = new Node(2);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    root->right->left = new Node(3);
    // root->right->right = new Node(7);
    inorder(root);
    cout<<endl;
    Flatten(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}