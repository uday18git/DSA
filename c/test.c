#include <stdio.h>
#include <stdlib.h>
int s = 0;

struct Node
{ // node declaration
    int data;
    struct Node *next;
};

void push_front(struct Node **head, int data)
{ // the head which is the address of the first memory location is passed

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // new node to be inserted is created

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void pop_front(struct Node **head)
{
    struct Node *temp = *head;

    if (*head == NULL)
    {
        printf("Container is empty"); // head doesn't point to anything
        return;
    }

    *head = (*head)->next; // deletion happens at the beginning i.e:-the front

    printf("Element popped is: %d", temp->data);
    printf("\n");
    free(temp);
}
void pop_back(struct Node **head)
{
    struct Node *temp = *head;
    struct Node *previous; // pointer that is used to make the link of the 2nd last element to point to null

    if (*head == NULL)
    {
        printf("Container is empty");
        return;
    }

    if (temp->next == NULL)
    { // if just one element exists in the linked list,that element is popped out and head is made to point to null
        printf("Element popped is: %d", (*head)->data);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
    {

        previous = temp; // reference to second last element passed to previous
        temp = temp->next;
    }
    previous->next = NULL; // last element after deletion made to point to null

    printf("Element popped is: %d", temp->data);
    printf("\n");
    free(temp); // memory allocated to temp is freed
}
void push_back(struct Node **head, int data)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // node to be added is created

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next; // linked list is traversed until it reaches the end of the list

    temp->next = newNode; // insertion occurs at the end of the list which is also known as the back
}

void display(struct Node *node)
{
    printf("Elements in container are:");

        while (node != NULL)
    {
        printf("%d ", node->data); // entire linked list is traversed and during traversal,data elements are also printed
        node = node->next;
    }
    printf("\n");
}
int size(struct Node *node)
{

    while (node != NULL)
    {
        s++;
        node = node->next;
    }
    return s; // computes the size of the linkedlist
}
int empty(struct Node **head)
{
    if (*head == NULL) // checks if linked list is empty or not
        return 1;
    else
        return 0;
}

int back(struct Node *node)
{

    while (node->next)
    {

        node = node->next;
    }
    return node->data; // returns the back
}
int front(struct Node **head)
{
    struct Node *temp = *head;
    return temp->data;
    // returns the front
}
void main()
{
    struct Node *head = NULL; // as head doesn't point to anything initially,it is initialized to NULL
    int n, flag = 0;
    int j;
    printf("Enter\n1.Push_front\n2.Push_back\n3.Pop_front\n4.Pop_back\n5.Back\n6.Front\n7.Display\n8.Size\n9.Exit\n");

    while (1)
    {
        printf("Enter a choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter element to be pushed at front: ");
            scanf("%d", &j);
            push_front(&head, j);
            break;
        case 2:
            printf("Enter element to be pushed at back: ");
            scanf("%d", &j);
            push_back(&head, j);
            break;
        case 3:
            pop_front(&head);
            break;
        case 4:
            pop_back(&head);
            break;
        case 5:
            printf("Element at the Back: %d\n", back(head));
            break;
        case 6:
            printf("Element at the Front: %d\n", front(&head));
            break;
        case 7:
            display(head);
            break;
        case 8:
            printf("Total size is: %d\n", size(head));
            break;
        case 9:
            flag = 1;
            printf("Program exit successfull\n");
            break;
        default:
            printf("Enter a valid option\n");
        }
        if (flag)
        {
            break;
        }
    }
}