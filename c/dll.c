#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *listptr;
void insert(listptr *first, int item)
{
    listptr nn;
    nn = (listptr)malloc(sizeof(struct node));
    nn->data = item;
    nn->llink = NULL;
    nn->rlink = NULL;
    if (*first)
    {
        nn->rlink = *first;
        (*first)->llink = nn;
    }
    *first = nn;
    return;
}
void del(listptr *first)
{
    int item;
    listptr temp;
    temp = *first;
    item = (*first)->data;
    *first = (*first)->rlink;
    (*first)->llink = NULL;
    free(temp);
}
void search(listptr first, int item)
{
    while (first)
    {
        if (first->data == item)
        {
            printf("\nFound");
            return;
        }
        else
            first = first->rlink;
    }
    printf("\nNot Found");
}
void display(listptr first)
{
    if (first)
        while (first)
        {
            printf("%d\t", first->data);
            first = first->rlink;
        }
    else
        printf("\nEmpty List");
}
void displayrev(listptr first)
{
    if(first)
    {
        while(first->rlink!=NULL)
        {
            first=first->rlink;
        }
        while(first)
        {
            printf("%d\t",first->data);
            first=first->llink;
        }
    }
    else
    {
        printf("Empty list");
    }
}


int main()
{
    listptr first=NULL;
    int ch, item;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display Rev\n5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element:\t");
            scanf("%d", &item);
            insert(&first, item);
            break;
        case 2:
            del(&first);
            break;
        case 3:
            printf("\nEnter element to be searched:\t");
            scanf("%d", &item);
            search(first, item);
            break;
        case 4:
            displayrev(first);
            break;
        case 5:
            exit(1);
        }
    }
}

