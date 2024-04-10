#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while (n)
        {
            fast = fast->next;
            n--;
        }
        if (!fast)
            return head->next;
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *delNode = slow->next;
        slow->next = slow->next->next; // very imp

        delete delNode;
        return head;
    }
};