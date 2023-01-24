#include<stdio.h>
#include<stdlib.h>

struct listnode{
    int data;
    struct listnode* link;
};
typedef struct listnode *listptr;


listptr header;
listptr last;

void insert(int i)
{
    listptr temp;
    temp=malloc(sizeof(struct listnode));
    temp->data=i;
    if(header->link==header)
    {
        temp->link=header;
        header->link=temp;
        last=temp;
    }
    else
    {
        temp->link=header;
        last->link=temp;
        last=temp;
    }
}

int delete()
{
    
    if(header->link==header)
    {
        printf("list is empty\n");
    }
    else
    {
        int a=header->link->data;
        header->link=header->link->link;
        return a;
    }
}

void display(listptr ptr)
{
    printf("\n");
    ptr=ptr->link;
    while(ptr!=header)
    {
        printf("%d",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

void main()
{
    int a,key,x,flag;
    header=malloc(sizeof(struct listnode));
    header->link=header;
    while(1)
    {
        printf("enter 1-add  2-delete  3-display 4-terminate \n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:printf("enter the element to be added\n");
            scanf("%d",&key);
            insert(key);
            break;
            case 2:x=delete();
            printf("deleted element from stack is %d\n",x);
            break;
            case 3:display(header);
            break;
            default:flag=1;
        }
        if(flag==1)
        {
            break;
        }
    }

}
