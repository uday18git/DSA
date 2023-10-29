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
// step 1 count the number of nodes
// step 2 make the last node point to the head
// step 3 cut the (len-k) and point it to null
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        int count=1;
        while(temp->next)
        {
            temp=temp->next;
            count++;
        }
        // now temp has the last node
        temp->next=head;
        temp=head;
        k=k%count;
        for(int i=0;i<(count-k)-1;i++)
        {
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;

    }
    };
// brute force at first i only used the two functions then i took into account that if k==length then return head and all
// class Solution {
// public:
//     ListNode* insertAtHead(ListNode* head,ListNode* last)
//     {
        
//         last->next=head;
//         head=last;
//         return head;
//     }
//     ListNode* removeLast(ListNode* head)
//     {
//         ListNode* temp=head;
//         while(temp->next->next)
//         {
//             temp=temp->next;
//         }
//         ListNode* last=temp;
//         temp->next=NULL;
//         return last;
//     }
//     ListNode* rotateRight(ListNode* head, int k) {
        

//         if(!head || !head->next)
//         {
//             return head;
//         }
//         ListNode* temp=head;
//         int count=0;
//         while(temp)
//         {
//             count++;
//             temp=temp->next;
//         }
//         if(count==k)
//         {
//             return head;
//         }
//         else if(count<k)
//         {
//             for(int i=0;i<(k%count);i++)
//             {
//                 ListNode* last=removeLast(head);
//                 head=insertAtHead(head,last);
//             }
//             return head;
//         }
//         else //count>k
//         {
//             for(int i=0;i<k;i++)
//             {
//                 ListNode* last=removeLast(head);
//                 head=insertAtHead(head,last);
//             }
//             return head;
//         }

        
//     }
// };

// O(k*n)