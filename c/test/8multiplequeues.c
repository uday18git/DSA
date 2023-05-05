#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int key;
}element;
struct queue{
	element data;
	struct queue *link;
};
typedef struct queue *queueptr;
queueptr front[100],rear[100];
void create()
{
	for(int i=0;i<100;i++)
	{
		front[i]=NULL;
		rear[i]=NULL;
	}
}
void add(element item,int i)
{
	queueptr temp;
	temp=(struct queue*)malloc(sizeof(struct queue));
	temp->data=item;
	temp->link=NULL;
	if(front[i])
	{
		rear[i]->link=temp;
	}
	else
	{
		front[i]=temp;
	}
	rear[i]=temp;
}
element delete(int i)
{
	queueptr temp=front[i];
	element item;
	element x;
	x.key=-1;
	if(!temp)
	{
		return x;
	}
	item=temp->data;
	front[i]=front[i]->link;
	free (temp);
	return item;
}
void display(int i)
{
    queueptr temp=front[i];
    for(;(temp)!=NULL;temp=temp->link)
    {
        printf("%d\t",(temp->data).key);
    }
}
void main(){
	 create();
     int a,j;
   	 while(1){
   	    printf("enter the queue number:\n");
    	scanf("%d",&a);
        printf("Enter 1 to add\n2 to delete\n3 to display.");
        int o;
        element item;
        scanf("%d",&o);
        switch (o)
        {
            case 1:    
                printf("Enter the item:\n");
                scanf("%d",&j);
                item.key=j;
                add(item,a);
                break;
            case 2:
                printf("%d",delete(a).key);
       	        break;
    	    case 3:
                display(a);
        }
    	printf("\nenter 0 to exit\n");
    	int b;
   	    scanf("%d",&b);
    	if (b==0)
    	{    
   		 break;
    	}
}
}

