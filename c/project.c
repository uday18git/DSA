#include<stdio.h>
#include<stdlib.h>
int size = 0;
int front;
struct Node{
    int data;
    struct Node *next;
};


void push_front(struct Node** head, int data){
    
   
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    
    
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    
}

void pop_front(struct Node** head){
    struct Node* temp = *head;
  
    if(*head == NULL){
        printf("Container is empty");
        return;
    }
    
   
    *head = (*head)->next;
    
    printf("%d", temp->data);
    free(temp);
}
void pop_back(struct Node** head){
    struct Node* temp = *head;
    struct Node* previous;
    
   
    if(*head == NULL){
        printf("Container is empty");
        return;
    }
    
    if(temp->next == NULL){
        printf("%d",(*head)->data);
        *head = NULL;
        return;
    }
    
   
    while (temp->next != NULL) 
    {
      
        previous = temp; 
        temp = temp->next; 
    }
    previous->next = NULL;
   
    
    free(temp);
   
}
void push_back(struct Node** head, int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;


    if(*head==NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = newNode;
}



void display(struct Node* node){
    printf("Elements in container are: \n");
    
   printf("\n");
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}
int sizel(struct Node* node){
  
    
   
    while(node!=NULL){
        size++;
        node = node->next;
    }
    return size;
}
int empty(struct Node** head)
{
    if(*head==NULL)
    return 1;
    else 
    return 0;
}

int back(struct Node* node){
    
    
   
    while(node->next){
       
        node = node->next;
    }
    return node->data;
}
void main()
{
  struct Node* head = NULL;
  push_front(&head,5);
  push_front(&head,34);
  push_front(&head,65);
  push_back(&head,1);
  push_back(&head,2);
  push_back(&head,3);
  display(head);
  pop_back(&head);
  display(head);
  pop_front(&head);
  display(head);
  pop_front(&head);
  display(head);
  printf("%d",back(head));
  display(head);

  
 
}
