// #include<bits/stdc++.h>
// class node{
//     public:
//     int data;
//     node* next;

//     node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };

// void insertAtTail(node* &head, int val){
//     node* n = new node(val);//new denotes the request for memory allocation on free store.
//     node* temp=head;

// }
// int main()
// {

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node* next;
};
void printll(node* n)
{
    while (n != NULL)
    {
        cout << n->value << "->";
        n = n->next;
    }
    cout<<"NULL"<<endl;
}
void reversePrint(node* llist) {
    // SinglyLinkedListNode* temp = llist;
    if(llist == NULL)
    {
        return;
    }
    llist = llist->next;
    reversePrint(llist);
    cout<<llist->value<<endl;


}
/* note --- if we are changing the list in the function then we need to pass pointer to a pointer */
void insertAtTheFront(node**head,int newVal)
{
    //1.prepare a newNode
    node* newNode = new node();
    newNode->value=newVal;
    //2.put it in fronnt of the list
    newNode->next= *head;

    //3.move head of the list to point to the newNode
    *head = newNode;

}
void insertAtTheEnd(node**head,int newVal)
{
    node* newNode = new node();//allocating the memory using new
    newNode->value = newVal;
    newNode->next = NULL;
    //see if ll is empty
    if( *head == NULL)
    {
        *head = newNode;
        return;
    }
    //traverse through the ll to find last element
    node* last = *head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next= newNode;


}
void insertAfter(node*previous,int newVal)
{
    if(previous==NULL)
    {
        cout<<"cannot be null"<<endl;
        return;
    }
    node* newNode = new node();
    newNode->value = newVal;
    newNode->next = previous->next;
    previous->next = newNode;

}
void deletion(node* *head,int val)
{
    node* temp = *head;
    while(temp->next->value != val)
    {
        temp = temp->next;
    }
    node* del = temp->next;
    temp->next=temp->next->next;
    delete del;
}
node* reversell(node* head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr ;
    
    while(currptr != NULL)
    {
        nextptr = currptr-> next;
        currptr->next = prevptr;
        //now forward the ll
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
//work in progress
// node* reversek(node* &head,int k)
// {
    
// }
void makeCycle(node* head,int pos)
{
    node* temp = head;
    node* startnode;
    int count = 1;
    while(temp->next == NULL)
    {
        if(count==pos)
        {
            startnode = temp;
        }
        count++;
        temp = temp->next;
    }
    temp->next = startnode;
}

bool detectCycle(node* head)
{
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            return true;
        }
    }
    return false;
    
}
//assuming that cycle has been detected.
void removeCycle(node*head)
{
    node* fast = head;
    node* slow = slow;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while(slow!=fast);
    fast = head;
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
//
int main()
{
    node *head = new node();
    node *second = new node();
    node *third = new node();
    head->next = second;
    second->next = third;
    third->next = NULL;
    head->value = 1;
    second->value = 2;
    third->value = 3;
    insertAtTheFront(&head,7);
    insertAtTheEnd(&head,10);
    // insertAfter(second,11);
    deletion(&head,11);
    printll(head);
    // printll(reversell(head));
    reversePrint(head);

}
