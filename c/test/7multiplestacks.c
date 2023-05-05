#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 30
typedef struct 
{
    int key
}element;
struct stack
{
    element data;
    struct stack* link;
};
typedef struct stack* stckptr;
stckptr top[MAXSIZE];
void push(element item,int i)
{
    stckptr temp;
    temp = (stckptr)malloc(sizeof(struct stack));
    temp->data=item;
    temp->link=top[i];
    top[i]=temp;
}
element pop(int i)
{
    stckptr temp;
    element item;
    temp=top[i];
    if(!temp)
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