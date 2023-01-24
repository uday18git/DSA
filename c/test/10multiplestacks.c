
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10  
typedef struct 
{
    int key;
}element;
struct stack
{
    element data;
    struct stack *link;
};
typedef struct stack* stckptr;
stckptr top[MAXSIZE];
void push(element item,int i)
{
    stckptr temp;
    temp = (stckptr)malloc(sizeof(struct stack));
    temp->data = item;
    temp->link = top[i];
    top[i]=temp;
}
element pop(int i)
{
    stckptr temp;
    element item;
    temp = top[i];
    if(temp==NULL)
    {
        item.key=-1;
        return item;
    }
    else
    {
        top[i]=top[i]->link;
        item = temp->data;
        free(temp);
        return item;
    }    
}
void display(int i)
{
    stckptr temp;
    temp = top[i];
    for(;temp;temp=temp->link)
    {
        printf("%d\t",temp->data);
    }
}
void main()
{
    int z, ch, i;
    element item;
    for (z = 0; z < MAXSIZE; z++)
        top[z] = NULL;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter item to be inserted:\t");
            scanf("%d", &item.key);
            printf("\nEnter stack number:\t");
            scanf("%d", &i);
            push(item, i - 1);
            break;
        case 2:
            printf("\nEnter stack number from which you would like to pop element:\t");
            scanf("%d", &i);
            item = pop(i - 1);
            if (item.key == -1)
                printf("\nEmpty stack");
            else
                printf("\nDeleted element:\t%d", item.key);
            break;
        case 3:
            printf("\nEnter stack number you would like to display:\t");
            scanf("%d", &i);
            display(i - 1);
            break;
        case 4:
            break;
        default:
            printf("\nWrong choice");
            break;
        }
    } while (ch != 4);
}
