#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int key;
}element;

void enqueue(element *ptr,int temp,int* rear,int *front,int n){
    if((*rear)>=n){
        printf("Queue Overflow\n");
        return ;
    }

    ptr[*rear].key=temp;
    (*rear)++;
}

int dequeue(element *ptr,int *rear,int *front){
    if((*front)>=(*rear)){
        printf("Queue Underflow\n");
        return -1;
    }

    int ret=ptr[(*front)++].key;

    if((*front)>=(*rear)){
        (*front)=0;
        (*rear)=0;
    }
    return ret;
}

int isfull(element *ptr,int rear,int front,int n){
    if(rear>=n){
        return 0;
    }
    return -1;
}

int isempty(element *ptr, int rear, int front){
    if(rear==0){
        return 0;
    }
    return -1;
}

void display(element *ptr,int rear,int front){
    int i;
    for(i=front;i<rear;i++){
        printf("%d ",ptr[i].key);
    }
    printf("\n");
}

void dble(element* ptr,int* n){
    ptr=realloc(ptr,(*n)*sizeof(element)*2);
    (*n)=(*n)*2;
}

int main(){
    int sign,n,ele,flag=0,rear,front;
    element *queue;
    while(1){
        if(flag==0){
            printf("Enter any key to create queue\n");
            getchar();
            printf("Enter the size of queue\n");
            scanf("%d",&n);
            queue=(element*)malloc(n*sizeof(element));
            rear=0;
            front=0;
            flag=1;
        }
        else{
            printf("1-Enqueue 2-Dequeue 3-Isempty 4-Isfull 5-Display 6-Reallocate memory 7-Exit\n");
            scanf("%d",&sign);
            switch (sign){
                case 1:
                    printf("Enter the element\n");
                    scanf("%d",&ele);
                    enqueue(queue,ele,&rear,&front,n);
                    break;
                case 2:
                    printf("Popped Element = %d\n",deque(queue,&rear,&front));
                    break;
                case 3:
                    (isempty(queue,rear,front)==0)? printf("Queue empty\n"):printf("No\n");
                    break;
                case 4:
                    (isfull(queue,rear,front,n)==0)? printf("Queue Full\n"):printf("No\n");
                    break;
                case 5:
                    display(queue,rear,front);
                    break;
                case 6:
                    printf("Old size = %d\n",n);
                    dble(queue,&n);
                    printf("New size = %d\n",n);
                    break;
                default:
                    exit(0);
            }
        }
    }
    
    free(queue);

    return 0;
}