#include <bits/stdc++.h> 
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution
{
    public:
    int solve(Node* head)
    {
        if(head==NULL)
        {
            return 1;
        }
        int carry = solve(head->next);
        head->data+=carry;
        if(head->data<10)
        {
            return 0;
        }
        else
        {
            head->data=0;
            return 1;
        }
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int carry = solve(head);
        if(carry)
        {
            Node* newnode = new Node(1);
            newnode->next = head;
            return newnode;
        }
        else
        {
            return head;
        }
    }
};
// BRUTE FORCE IS TO REVERSE THE LL AND KEEP ADDING