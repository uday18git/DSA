#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int key;
}element;
void copy(int q1,int q2,int nq1,element *queue,element *newqueue)
{   int i,j;
    for(i=q1,j=nq1;i<=q2;i++,j++)
    {
        newqueue[j]=queue[i];
    }
}
element* queuefull(int *capacity,int *rear,int *front,element *queue)
{
    printf("queue is full and hence resized.PLease call again to add new element\n");
    element *newqueue;
    newqueue=(element*)malloc(2*(*capacity)*sizeof(element));
    int start=(*front+1)%(*capacity);
    if(start<2)
    {
        copy(start,start+(*capacity)-1,0,queue,newqueue);
    }
    else
    {
        copy(start,(*capacity)-1,0,queue,newqueue);
        copy(0,*rear,(*capacity)-start,queue,newqueue);
    }
    *front=0;
    *rear=(*capacity)-1;
    (*capacity)*=2;
    return newqueue;
}
void queueempty(int *rear,int *front)
{
    if(*rear==*front)
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue is not empty\n");
    }
}

void addq(int *rear,int *front,int *capacity,int item,element *queue)
{
    int newrear;
    newrear=((*rear)+1)%(*capacity);
    if(*front==newrear)
    {
        queue=queuefull(capacity,rear,front,queue);
    }
    else
    {
        *rear=newrear;
        queue[*rear].key=item;
    }
}

element deleteq(int *rear,int *front,int capacity,element *queue)
{
    if(*front==*rear)
    {
        queueempty(rear,front);
    }
    else
    {   printf("%d",*front);
        *front=((*front)+1)%capacity;
       printf("%d",*front);
        return queue[*front];
    }
}
void display(int *rear,int *front,int capacity,element *queue)
{
    for(int i=*front+1;i<(*front)+1+(*rear-*front+capacity)%capacity;i++){
        printf("%d\n",queue[i%capacity].key);
    }
}
void main()
{
    int rear=0,front=0,capacity,temp,item,flag=0;
    element b;
    element *queue;
    printf("enter the capcity of queue\n");
    scanf("%d",&capacity);
    queue=(element*)malloc(capacity*sizeof(element));
    while(1)
    {
        printf("enter \n1-add element\n2-delete element\n3-to check if queue is empty\n4-display\n5--terminate\n");
        scanf("%d",&temp);
        switch(temp)
        {
            case 1:printf("enter the element to be added\n");
            scanf("%d",&item);
            addq(&rear,&front,&capacity,item,queue);
            printf("%d%d",front,rear);
            break;
            case 2:b=deleteq(&rear,&front,capacity,queue);
            printf("deleted element is:%d\n",b.key);
            break;
            case 3:queueempty(&rear,&front);

            break;
            case 4:display(&rear,&front,capacity,queue);
            break;
            case 5:flag=1;
            break;
            default:printf("invalid input");
        }
        if(flag==1)
        {
            break;
        }
    }
    
}
