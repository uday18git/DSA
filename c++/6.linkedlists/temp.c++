#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int x)
    {
        val = x;
        next=NULL;
    }
};

// write function for detete
// intert at front
// reverse ll
// detect cycle
// remove cycle

void makeCycle(Node* head, int pos) {
    if (head == nullptr) return; // Handle empty list
    Node* temp = head;
    Node* startnode = nullptr;
    int count = 1;
    while (temp->next != nullptr) {
        if (count == pos) {
            startnode = temp;
        }
        count++;
        temp = temp->next;
    }
    if (count == pos) { // if position is at the last node
        startnode = temp;
    }
    if (startnode != nullptr) {
        temp->next = startnode;
    }
}


bool detectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
        {
            return true;
        }
    }
    return false;
}

void printll(Node* head)
{
    Node* temp =head;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void delNode(Node* head,int x)
{
    Node* temp = head;
    while(temp->next->val !=x)
    {
        temp=temp->next;
    }
    temp->next = temp->next->next; //deleted......
}
Node* reverseLL(Node* &head)
{
    Node* prevptr = NULL;
    Node* currptr = head;
    Node* nextptr;
    while(currptr)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

Node* reverseLL(Node* &head)
{
    if(!head || !head->next)
    {
        return head;
    }
    Node* temp = reverseLL(head->next);
    head->next->next= head;
    head->next = NULL;
    return temp;
}
void insertAF(Node* &head,int x)
{
    Node* temp = new Node(x);
    temp->next=head;
    head=temp;
}

int main()
{

    Node* f = new Node(1);
    f->next= new Node(2);
    f->next->next = new Node(3);
    f->next->next->next = new Node(4);
    printll(f);
    delNode(f,2);
    // insertAF(f,5);
    // makeCycle(f,3);
    // cout<<detectCycle(f);
    printll(f);

}



// Certainly! Let's break down the line of code `Node* temp = new Node(x);` step by step.

// ### Assumptions
// 1. **Node Structure**: Assume a simple `Node` structure is defined as follows:
//     ```cpp
//     struct Node {
//         int data;
//         Node* next;
        
//         Node(int x) : data(x), next(nullptr) {}
//     };
//     ```

// 2. **Value of `x`**: Let's assume `x` is 42 for this example.

// ### Explanation

// 1. **Memory Allocation**:
//     - The `new` keyword dynamically allocates memory for a `Node` object on the heap.
//     - Let's say this memory is allocated at address `0x100`.

// 2. **Constructor Call**:
//     - `new Node(x)` calls the constructor `Node(int x)`, initializing `data` to `42` and `next` to `nullptr`.

// 3. **Pointer Assignment**:
//     - `Node* temp` declares a pointer `temp` that can point to a `Node`.
//     - The assignment `temp = new Node(x)` sets `temp` to point to the newly allocated `Node` object at address `0x100`.

// ### Memory Locations and Values

// 1. **Heap Memory**:
//     - At address `0x100`:
//         - `data`: `42`
//         - `next`: `nullptr` (or `0x0`)

// 2. **Stack Memory**:
//     - Pointer `temp`:
//         - Assume `temp` itself is stored at address `0x200` on the stack.
//         - The value at address `0x200` is `0x100`, pointing to the heap-allocated `Node`.


// VERY NICE VISUALIZATION
// ### Visualization

// #### Heap
// ```
// Address: 0x100
// --------------
// | data: 42   |
// | next: 0x0  |
// --------------
// ```

// #### Stack
// ```
// Address: 0x200
// --------------
// | temp: 0x100 |
// --------------
// ```

// ### Summary

// The line `Node* temp = new Node(x);` does the following:
// 1. Allocates memory for a `Node` on the heap (e.g., at address `0x100`).
// 2. Initializes the `data` member of the `Node` to `42` and the `next` member to `nullptr`.
// 3. Creates a pointer `temp` on the stack (e.g., at address `0x200`) that points to the allocated `Node` on the heap. 

// In essence, `temp` now holds the memory address of the newly created `Node`, allowing you to access and manipulate it through `temp`.