//  Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// brute force solution
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)return head;
        vector<int> arr;
        ListNode* temp=head;
        // to get even indices
        while(temp && temp->next)
        {
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)arr.push_back(temp->val);
        // to get odd indices
        temp=head->next;
        while(temp && temp->next)
        {
            arr.push_back(temp->val);
            temp=temp->next->next;
        }
        if(temp)
        {
            arr.push_back(temp->val);
        }
        temp=head;
        int i=0;
        while(temp)
        {
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};



// optimized solution
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next)return head;
        ListNode* even=head;
        ListNode* odd=head->next;
        ListNode* temp=head->next;
        while(odd && odd->next)
        {
            even->next=even->next->next;
            odd->next=odd->next->next;
            even=even->next;
            odd=odd->next;
        }
        even->next=temp;
        return head;
    }
};

