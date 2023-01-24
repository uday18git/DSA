#include<stdio.h>
#include<stdlib.h>
struct node
{
    int expo;
    int coef;
    struct node* link;
};
typedef struct node* polyptr;
polyptr cpadd(polyptr a,polyptr b)
{
    polyptr lastC,startA,c;
    int sum=0,done=0;
    c = (polyptr)malloc(sizeof(struct node));
    c->expo =-1;
    lastC = c;
    startA = a;
    a = a->link;
    b = b->link;
    switch(COMPARE(a->expo,b->expo))
    {
        case 1:
        attach(a->coef,a->expo,&lastC);
        a=a->link;
        break;
        case 0:
        if(startA==a)
        {
            done=1;
        }
        sum=a->coef+b->coef ;
        attach(sum,b->expo,&lastC);
        

    }
}
void attach(int coeff,int expon,polyptr *ptr)
{
    polyptr temp;
    temp = (polyptr)malloc(sizeof(struct node));
    temp->coef=coeff;
    temp->expo=expon;
    (*ptr)->link=temp;
    (*ptr)=temp;
}
void readPoly(polyptr *a)
{
    polyptr temp;
    *a = (polyptr)malloc(sizeof(struct node));
    temp = *a;
    (*a)->expo = -1;
    int n,i,coef,expo;
    printf("Enter the number of elements in poly");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter coef and expon");
        scanf("%d%d",&coef,&expo);
        attach(coef,expo,&temp);
    }
    temp->link = *a;
}
void main()
{
    polyptr a,b,c;
    readPoly(&a);
    printPoly(a);
    readPoly(&b);
    printPoly(b);
    c = cpadd(a,b);
    printPoly(c);
}