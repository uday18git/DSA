#include <bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// optimal approach
// merge sort approach this is
class Solution
{
public:
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *prev;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        return prev;
    }
    ListNode *merge2LL(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        if (list1->val > list2->val) // we have to always keep l1 as the smaller list
        {
            // swapping
            ListNode *temp = list1;
            list1 = list2;
            list2 = temp;
        }
        ListNode *res = list1;
        while (list1 && list2)
        {
            ListNode *temp = NULL;
            // till l1 is lesser than l2
            while (list1 && list2->val >= list1->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            // swapping again as we have to keep l1 as the smaller one always
            temp = list1;
            list1 = list2;
            list2 = temp;
        }
        return res;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *middle = findMiddle(head);
        ListNode *left = head;
        ListNode *right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge2LL(left, right);
    }
};

// BRUTE FORCE APPROACH
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        vector<int> arr;
        ListNode *temp = head;
        while (temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        temp = head;
        while (temp)
        {
            temp->val = arr[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};