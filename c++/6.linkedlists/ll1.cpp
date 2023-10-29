#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;

}

void insertAtHead(node* & head,int val)
{
    node* n= new node(val);
    n->next=head;
    head=n;
}
void display(node*  head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
    cout<<endl;
}
bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void deleteAtHead(node* &head)
{
    node* todelete=head;
    head=head->next;
    delete todelete;

}
void deletion(node* &head,int val) //corner case is when we try to delete the head node only , so we make a seperate function for that
{
    if(head==NULL)//corner case handled
    {
        return;
    }
    if(head->next==NULL)//corner case handled
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val)
    {
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;

}

//reversing a linked list
// two methods -> iterative method and recursive method
// we take three pointers previous ,current and next
// initially we take previous as null , we have to remove the link between current and next and make a link between current and previous (previous<-current)
// and we have break the loop at current == null, because at this condition the linked list has been reversed



node* reverse(node* &head)
{
    node*currptr=head;
    node*prevptr=NULL;
    node*nextptr; // we have to initialise this in the while loop
    while(currptr)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr ; //because this is our new head
}
// recursive way , we call it on head->next itseems
//  we have to call it on head->next and we have to manually adjust the head  node
// we have to make the second node point to head(head->next->next=head) and head->next=NULL
node* reverseRecursive(node*&head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

//reverse k nodes
// first k nodes we use iterative method to reverse, and rest of the nodes we call our function again(recursion)
// after reversing nodes generally last node is prev, curr is null like that  , and we have to point head's next to the rest(excluding the first k elements) of the array's first element 

node* reversek(node* &head,int k) // last part didnt understand
{
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while(currptr && count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if(nextptr)
    {
        head->next=reversek(nextptr,k); // head->next we need to point to the rest of the array
    }
    return prevptr; // new head
}

// floyd's algorithm, rabbit and tortoise, detection and removal of cycle in linked list
// take one fast, slow, fast moves two steps ahead, and slow moves one step ahead at a time.
// and if they meet at a point then it has a cycle otherwise does not have a cycle
bool detectCycle(node* &head)
{
    node*slow = head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){ // second condition because fast moves 2 steps at a time
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}
void makeCycle(node* &head,int pos)
{
    node* temp=head;
    node* cycleNode;
    int count=1;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            cycleNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=cycleNode;

}
// to remove a cycle
// we make fast move 2 steps at once and slow move 1 step at once okay, then next
// after they are at same position we take fast or slow (one of them )  and put it at head
// they will reach the position at where the cycle is there at the same time, so 
// supppose we take fast to be head 
// then when both are about to go to the cycle node, 
// we break apart the slow node and point it to null

void removecycle(node* &head)
{
    node*slow=head;
    node*fast=head;
    while(fast != slow)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    fast=head;
    while(fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
    return ;
}
// append last k nodes to the front of the linked list
void lastk(node*&head,int k)
{
    node* temp=head;

    int count=1;
    while(temp->next)
    {
        temp=temp->next;
        count++;
    }

    temp->next=head;

    temp=head;
    int num=1;
    while(num<(count-k))
    {
        temp=temp->next;
        num++;
    }
    head=temp->next;
    temp->next=NULL;

}


int main()
{
    node* head=NULL;
    //1
    for(int i=1;i<=6;i++)
    {
        insertAtTail(head,i);
    }
    //2
    display(head);
    //3
    // insertAtHead(head,4);
    // display(head);
    //4
    // cout<<search(head,5)<<endl;
    //5
    // deletion(head,3);
    // display(head);
    //6
    // deleteAtHead(head);
    // display(head);
    //7
    // node* newhead = reverseRecursive(head);
    // display(newhead);
    //8 
    // node* x= reversek(head,2);
    // display(x);
    //9
    // makeCycle(head,3);
    // display(head);
    //10
    // cout<<detectCycle(head)<<endl;
    //11
    // makeCycle(head,3);
    // cout<<detectCycle(head)<<endl;
    // removecycle(head);
    // cout<<detectCycle(head)<<endl;
    //proof idk fk it
    //12
    // lastk(head,3);
    // display(head);
    //13
    // find intersection point

    return 0;
}


// below code is for find_intersection_point
// to find intersection point of two linked lists
// two ways to do this, first -> O(N+M) traverse one of the linked list and mark all the nodes as visited
// next traverse the other linked list and if any of the nodes is marked visited then it is the intersection point


// better way to do it is
// see which one is bigger
// take start from m-n th node of that , then keep increasing one one node of that then you will get one node as equal


// #include <iostream>
// using namespace std;

// class node {
// public:
//     int data;
//     node* next;

//     node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// void insertAtTail(node* &head, int val) {
//     node* n = new node(val);
//     if (head == NULL) {
//         head = n;
//         return;
//     }
//     node* temp = head;
//     while (temp->next != NULL) {
//         temp = temp->next;
//     }
//     temp->next = n;
// }

// node* find_intersection_point(node* head1, node* head2) {
//     if (head1 == NULL || head2 == NULL) {
//         return NULL;
//     }

//     // Find the lengths of the two linked lists
//     int len1 = 0, len2 = 0;
//     node* temp1 = head1;
//     node* temp2 = head2;

//     while (temp1 != NULL) {
//         len1++;
//         temp1 = temp1->next;
//     }

//     while (temp2 != NULL) {
//         len2++;
//         temp2 = temp2->next;
//     }

//     // Reset temp1 and temp2 to the heads of the linked lists
//     temp1 = head1;
//     temp2 = head2;

//     // Move the pointer of the longer list ahead by the difference in lengths
//     if (len1 > len2) {
//         int diff = len1 - len2;
//         for (int i = 0; i < diff; i++) {
//             temp1 = temp1->next;
//         }
//     } else if (len2 > len1) {
//         int diff = len2 - len1;
//         for (int i = 0; i < diff; i++) {
//             temp2 = temp2->next;
//         }
//     }

//     // Traverse both lists until we find the intersection point
//     while (temp1 != NULL && temp2 != NULL) {
//         if (temp1 == temp2) {
//             return temp1;
//         }
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }

//     return NULL; // No intersection found
// }

// int main() {
//     node* head1 = NULL;
//     node* head2 = NULL;

//     for (int i = 1; i <= 6; i++) {
//         insertAtTail(head1, i);
//     }

//     node* temp1 = head1;

//     for (int i = 1; i <= 5; i++) {
//         temp1 = temp1->next;
//     }

//     node* intersection = new node(7);

//     for (int i = 1; i <= 3; i++) {
//         insertAtTail(head2, i);
//     }

//     temp1->next = intersection;

//     // Find the intersection point
//     node* result = find_intersection_point(head1, head2);

//     if (result != NULL) {
//         cout << "Intersection point: " << result->data << endl;
//     } else {
//         cout << "No intersection point found." << endl;
//     }

//     return 0;
// }