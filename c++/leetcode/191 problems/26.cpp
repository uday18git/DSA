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

 // optimal approach 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};



// naive approach is to count number of nodes and give the middle haina
// if there are 2 middle nodes we have to give the second node
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* temp=head;
//         int count=0;
//         while(temp)
//         {
//             count++;
//             temp=temp->next;
//         }
        
//         int mid=count/2 ;
//         temp=head;
//         while(mid)
//         {
//             temp=temp->next;
//             mid--;
//         }
//         return temp;
       
        
//     }
// };