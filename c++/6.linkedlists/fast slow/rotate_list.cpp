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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head)return head;
        ListNode* temp = head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        k=k%count;
        if(k==0)return head;
        temp=head;
        while(k)
        {
            temp=temp->next;
            k--;
        }
        ListNode* temp1 = head;
        while(temp->next)
        {
            temp=temp->next;
            temp1=temp1->next;
        }
        // now temp is on the last node and temp1 is on the k-nth node
        ListNode* temp2=temp1->next;
        temp1->next=NULL;
        temp->next=head;
        return temp2;
    }
};