#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        next = NULL;
    }

};
void printll(Node* head)
{
    if(head->next==NULL)
    {
        cout<<head->data;
        return;
    }
    cout<<head->data<<" -> ";
    printll(head->next);
}
void reverse(Node* head)
{
    if(head->next==NULL)
    {
        cout<<head->data<<" ";
        return;
    }
    reverse(head->next);
    cout<<head->data<<" ";
}
Node* insertAtTheFront(Node* head,int val)
{
    Node* newHead = new Node(val);
    newHead->next = head;
    return newHead;
}
// iterative method
Node* reversell(Node* head)
{
    Node* currptr = head;
    Node* prevptr = NULL;
    Node* nextptr;
    while(currptr)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
int main()
{
    Node* first = new Node(1);
    first->next = new Node(2);
    first->next->next = new Node(3);
    // reverse(first);
    Node* newhead = reversell(first);
    printll(newhead);


}