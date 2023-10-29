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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        ListNode* nextptr;
        int count=0;
        // Count the number of nodes in the current group
        ListNode* temp = head;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }
        
        if (count < k) {
            // If there are less than k nodes, don't reverse, return the original sublist
            return head;
        }
        
        count = 0;
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
            head->next=reverseKGroup(nextptr,k); // we have to point head->next to the remaining(excluding first k) ll
        }
        return prevptr; // because it will be the new head
        
    }
};