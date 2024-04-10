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

// naive approach
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> list;
        while (temp)
        {
            list.push_back(temp->val);
            temp = temp->next;
        }
        int n = list.size();
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            if (list[start] != list[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};



// optimzed approach
class Solution
{
public:
    ListNode *reverseList(ListNode *&head)
    {
        ListNode *prevptr = NULL;
        ListNode *currptr = head;
        ListNode *nextptr;
        while (currptr)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        return prevptr;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        // fisrt we are finding out the middle element
        while (fast && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // now middle element is in slow
        // if it is even length then we are finding out the first middle element
        // now we have to reverse the remaining ll;
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (true)
        {
            if (slow == NULL)
            {
                return true;
            }
            if (slow->val == head->val)
            {
                slow = slow->next;
                head = head->next;
            }
            else
            {
                return false;
            }
        }
    }
};

// naive approach will be to put it in a vector or array and check if that is palindrom or not
// so that will use a extra space of O(N)

// we need to find the middle of the linked list
// if we reach the second last or the last node we have to stop (to do this we have to see
// whether the fast->next->next is also there
// after finding the first middle node(applicable for even length ll)
// we will reverse the rest of the ll following the middle node
// after reversing take a dummy node from the starting and start traversing the slow pointer and
// dummy pointer, if the slow pointer reaches null then it is palindrome
// O(n/2) + O(n/2) +O(n/2) + O(n/2) + O(n/2),
// sc O(1)