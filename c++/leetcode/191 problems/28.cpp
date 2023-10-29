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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int lol=1;
        ListNode* temp=head;
        // calculating the length of the ll
        while(temp->next!=NULL)
        {
            temp=temp->next;
            lol++;
        }
        if(lol==1)
        {
            return NULL;
        }
        int count=1;
        cout<<lol<<endl;
        temp=head;
        // stores the previous value of the node to be deleted in temp
        while(count<(lol-n))
        {
            temp=temp->next;
            count++;
        }
        
        cout<<count<<" "<<temp->val;
        if(lol==n)
        {
            head=head->next;
        }
        else
        {
            temp->next=temp->next->next;
        }
        return head;
    }
};