#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertAtTail(node* head,int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* temp = head;
    node* newNode = new node(val);
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

}
//if head is NULLL
void insertAtHead(node* head,int val)
{
    node* newnode = new node(val);
    
    newnode->next = head;
    if(head!= NULL)
    {
        head->prev = newnode;
    }
    head = newnode;

}
void display(node* head)
{
    node* temp = head;
    cout<<"NULL->";
    //if head is null we cant do so...
    while(temp!= NULL)
    {
        cout<<temp->data<<"->";
    }
    cout<<"->NULL";

}
void deleteNode(node* head,int pos)
{
    if(pos==1)
    {
        deleteathead(head);
        return;
    }
    int counter=1;
    node* temp = head;
    while(counter<pos)
    {
        temp=temp->next;
        counter++;
    }
    temp->prev->next=temp->next;
    //wont workk if we want to delete the last node so...
    if(temp->next!=NULL)
    {
        temp->next->prev=temp->prev;
    }
    delete temp;
}
void deleteathead(node* head)
{
    //delete head; wont work we have to write a complete seperate function for this
    node* todelete = head;
    head=head->next;
    head->prev = NULL;
    delete todelete;
}