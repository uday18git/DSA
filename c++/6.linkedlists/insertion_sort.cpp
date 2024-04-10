/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// half working implementation 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* prev=head;
        ListNode* newHead=head;
        while(temp)
        {
            if(temp->val<prev->val)
            {
                prev->next=prev->next->next;
                ListNode* temp1=newHead;
                ListNode* prev1=newHead;
                bool flag=false;
                while(temp1->val<temp->val)
                {
                    flag=true;
                    prev1=temp1;
                    temp1=temp1->next;
                }
                if(!flag)
                {
                    temp->next=head;
                    newHead=temp;
                }
                else
                {
                    prev1->next=temp;
                    temp->next=temp1;
                }
                // prev->next=prev->next->next;

                
            }
            prev=temp;
            temp=temp->next;
        }
        return newHead;
    }
};