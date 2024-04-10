#include<bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val >list2->val) // we have to always keep l1 as the smaller list
        {
            // swapping
            ListNode* temp = list1;
            list1=list2;
            list2=temp;
        }
        ListNode* res=list1;
        while(list1 && list2)
        {
            ListNode* temp = NULL;
            // till l1 is lesser than l2 
            while(list1 && list2->val>=list1->val)
            {
                temp = list1;
                list1=list1->next;
            }
            temp->next=list2;
            // swapping again as we have to keep l1 as the smaller one always
            temp = list1;
            list1=list2;
            list2=temp;
        }
        return res;
    }
};


// BRUTE FORCE APPROACH 
// #include <bits/stdc++.h>
// using namespace std;
// class node
// {
// public:
//     int value;
//     node *next;
// };
// void printll(node *n)
// {
//     while (n != NULL)
//     {
//         cout << n->value << "->";
//         n = n->next;
//     }
//     cout << "NULL" << endl;
// }
// void merge(node *head1, node *head2)
// {
//     node *ptr1 = head1;
//     node *ptr2 = head2;
//     node *ptr3 = new node();
//     while ((ptr1!= NULL && ptr2!= NULL))
//     {
//         if (ptr2->value > ptr1->value)
//         {
//             ptr3->next = ptr1;
//             ptr1 = ptr1->next;
//         }
//         else if (ptr1->value > ptr2->value)
//         {
//             ptr3->next = ptr2;
//             ptr2 = ptr2->next;
//         }
//         ptr3 = ptr3->next;
//     }
//     while(ptr1!=NULL)
//     {
//         ptr3->next = ptr1; 
//         ptr1 = ptr1->next;
//         ptr3 = ptr3->next;
//     }
//     while(ptr2!=NULL)
//     {
//         ptr3->next = ptr2; 
//         ptr2 = ptr2->next;
//         ptr3 = ptr3->next;
//     }
// }
// void insertAtTail(node**head,int newVal)
// {
//     node* newNode = new node();//allocating the memory using new
//     newNode->value = newVal;
//     newNode->next = NULL;
//     //see if ll is empty
//     if( *head == NULL)
//     {
//         *head = newNode;
//         return;
//     }
//     //traverse through the ll to find last element
//     node* last = *head;
//     while(last->next != NULL)
//     {
//         last = last->next;
//     }
//     last->next= newNode;


// }
// int main()
// {
//     node* head1 = NULL;
//     node* head2 = NULL;
//     int arr1[] = {1,4,5,7};
//     int arr2[] = {2,3,6};
//     for(int i=0;i<4;i++)
//     {
//         insertAtTail(&head1,arr1[i]);
//     }
//     for(int i=0;i<3;i++)
//     {
//         insertAtTail(&head2,arr2[i]);
//     }
// }