// linked list is a linear data structure , stores a list of values
// array is a single block of memory with partitions
// linked list is multiple blocks of connected memory
// can be spread out in the heap memory

// limitations of arrays
// size is fixed , wasted if less memory is used, and overflow if more is used
// contigous block of memory
// inserting and deleting is costly

// we can do both
// Node* nodePtr = new Node(10);
// (*nodePtr).data = 20; // Accesses and sets the 'data' member to 20
// (*nodePtr).next = new Node(30); // Creates a new node and assigns it to 'next'
// Node* nodePtr = new Node(10);
// nodePtr->data = 20; // Accesses and sets the 'data' member to 20
// nodePtr->next = new Node(30); // Creates a new node and assigns it to 'next'



#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};



void deleteAtHead(node* &head)
{
    node *todelete = head;
    head = head->next;
    delete todelete;
}



// in delete there are 3 types, when head and val is given , when the node is given , and when the previous element is given
void deletion(node *&head, int val) // corner case is when we try to delete the head node only , so we make a seperate function for that
{
    if (head == NULL) // corner case handled
    {
        return;
    }
    if (head->next == NULL) // corner case handled
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}



// deletion in linked list when the node which has to be deleted is given
// unintuitive
class Solution
{
public:
    void deleteNode(node *node1)
    {
        node1->val = node1->next->val;
        node1->next = node1->next->next;
    }
}


// reversing a linked list
//  two methods -> iterative method and recursive method
//  we take three pointers previous ,current and next
//  initially we take previous as null , we have to remove the link between current and next and make a link between current and previous (previous<-current)
//  and we have break the loop at current == null, because at this condition the linked list has been reversed

node* reverse(node *&head)
{
    node *currptr = head;
    node *prevptr = NULL;
    node *nextptr; // we have to initialise this in the while loop
    while (currptr)
    {
        nextptr = currptr->next; // defining nextptr
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr; // because this is our new head
}
// recursive way , we call it on head->next itseems
//  we have to call it on head->next and we have to manually adjust the head  node
// we have to make the second node point to head(head->next->next=head) and head->next=NULL
// class Solution
// {
// public:
//     ListNode *reverseList(ListNode *head)
//     {
//         if (head == NULL || head->next == NULL)
//             return head;
//         ListNode *newhead = reverseList(head->next); // one call of recursion means that it will give back the rest of the list with reversed
//         head->next->next = head; // on first return this will make the last pointer to point to its prev ptr
//         head->next = NULL; // making the next pointer of the second last pointer from last pointer to NULL 
//         return newhead;
//     }
// };
// when i call recursion on heads next it should return reversed list till head's next, then we are reversing the rest, that is head and its next
// using head->next->next = head
// head->next=NULL

// 1->2->3->4->NULL

// short of reverse k group
// normal reverse list with a count variable and while is count<k 
//  and at last if(nextptr) still there are nodes left to process then head->next = reversekgroup(nextptr,k)
//  and return prevptr like normal reverse list function
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *currptr = head;
        ListNode *prevptr = NULL;
        ListNode *nextptr;
        int count = 0;
        ListNode *temp = head;
        // counting the number of nodes in the current recursion call
        while (temp && count < k)
        {
            temp = temp->next;
            count++;
        }
        // handling the case when there are less than k nodes
        if (count < k)
        {
            return head;
        }
        count = 0;
        while (currptr && count < k)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        if (nextptr)
        {
            head->next = reverseKGroup(nextptr, k);
        }
        return prevptr;
    }
};


// floyd's algorithm, rabbit and tortoise, detection and removal of cycle in linked list
// take one fast, slow, fast moves two steps ahead, and slow moves one step ahead at a time.
// and if they meet at a point then it has a cycle otherwise does not have a cycle
bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    { // second condition because fast moves 2 steps at a time
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}


void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *cycleNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = cycleNode;
}

// to remove a cycle
// we make fast move 2 steps at once and slow move 1 step at once okay, then next
// after they are at same position we take fast or slow (one of them )  and put it at head
// they will reach the position at where the cycle is there at the same time, so
// supppose we take fast to be head
// then when both are about to go to the cycle node,
// we break apart the slow node and point it to null

void removecycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    // this we can do only when we certainly know that cycle is there , if we donno then its the below implementation
    while (fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
    return;
}


// FAST SLOW PATTERN
// REMOVE THE NTH NODE FROM END
// TRAVERSE N NODES FROM THE START USING FAST POINTER
// THEN START THE SLOW POINTER FROM HEAD AND , TRAVERSE BOTH OF THEM TOGETHER .
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


// REMOVE MID , fast slow
#include<bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// we have to maintain a previous pointer also to makes sure that when the length is 2 
//  we can make the previous's next NULL ,  
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev=NULL;
        while(fast && fast->next)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        // now slow has the middle element
        // deleting the middle element
        if(!slow->next)
        {
            // slow=NULL; THIS WONT WORK BECAUSE IT DOESNT CHANGE WHAT THE PREVIOUS ELEMENT WAS POINTING TO
            prev->next=NULL;
            return head;
        }
        slow->val = slow->next->val;
        slow->next=slow->next->next;
        // or you can also delete the element using
        // prev->next=prev->next->next;
        return head;
    }
};


//  Definition for singly-linked list.
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

// naive approach
// store the values in a list and check if palindrom using two pointer approach
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
        // first we are finding out the middle element
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




// even odd 

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

// brute force solution
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(!head || !head->next)return head;
//         vector<int> arr;
//         ListNode* temp=head;
//         // to get even indices
//         while(temp && temp->next)
//         {
//             arr.push_back(temp->val);
//             temp=temp->next->next;
//         }
//         if(temp)arr.push_back(temp->val);
//         // to get odd indices
//         temp=head->next;
//         while(temp && temp->next)
//         {
//             arr.push_back(temp->val);
//             temp=temp->next->next;
//         }
//         if(temp)
//         {
//             arr.push_back(temp->val);
//         }
//         temp=head;
//         int i=0;
//         while(temp)
//         {
//             temp->val=arr[i];
//             temp=temp->next;
//             i++;
//         }
//         return head;
//     }
// };



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


// SORT LIST

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


#include<bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        if(list1->val >list2->val) // we have to always keep l1 as the smaller list
        {
            // swapping
            ListNode* temp = list1;
            list1=list2;
            list2=temp;
        }
        ListNode* res=list1;
        while(list1 && list2)
        {
            ListNode* temp = NULL;
            // till l1 is lesser than l2 
            while(list1 && list2->val>=list1->val)
            {
                temp = list1;
                list1=list1->next;
            }
            temp->next=list2;
            // swapping again as we have to keep l1 as the smaller one always
            temp = list1;
            list1=list2;
            list2=temp;
        }
        return res;
    }
};



// ADD 2 NUMBERS

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1 || l2 || carry)
        {
            int sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode * node=new ListNode(sum%10);
            temp->next=node;
            temp=temp->next;
        }
        return dummy->next;
    }
};



#include <bits/stdc++.h> 
using namespace std;
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution
{
    public:
    int solve(Node* head)
    {
        if(head==NULL)
        {
            return 1;
        }
        int carry = solve(head->next);
        head->data+=carry;
        if(head->data<10)
        {
            return 0;
        }
        else
        {
            head->data=0;
            return 1;
        }
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int carry = solve(head);
        if(carry)
        {
            Node* newnode = new Node(1);
            newnode->next = head;
            return newnode;
        }
        else
        {
            return head;
        }
    }
};
// BRUTE FORCE IS TO REVERSE THE LL AND KEEP ADDING



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