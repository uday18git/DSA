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


// we have to maintain a previous pointer also to makes sure that when the length is 2 
//  we can make the previous's next NULL ,  
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev=NULL;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        // now slow has the middle element
        // deleting the middle element
        if(!slow->next)
        {
            // slow=NULL; THIS WONT WORK BECAUSE IT DOESNT CHANGE WHAT THE PREVIOUS ELEMENT WAS POINTING TO
            prev->next=NULL;
            return head;
        }
        slow->val = slow->next->val;
        slow->next=slow->next->next;
        // or you can also delete the element using
        // prev->next=prev->next->next;
        return head;
    }
};