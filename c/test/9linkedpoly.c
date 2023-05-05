// #include<stdio.h>
// #include<stdlib.h>
// #define COMPARE(x,y)(x>y?1:(x<y?-1:0))
// struct node
// {
//     int expo;
//     int coeff;
//     struct node* link;
// };
// typedef struct node* polyptr;
// polyptr a,b;
// void attach(int coefficient,int exponent,polyptr *ptr)
// {
//     polyptr temp;
//     temp = (polyptr)malloc(sizeof(struct node));
//     temp->expo = exponent;
//     temp->coeff = coefficient;
//     (*ptr)->link=temp;
//     *ptr = temp;
// }
// polyptr cpadd(polyptr a,polyptr b)
// {
//     polyptr c,lastC,startA;
//     c = (polyptr)malloc(sizeof(struct node));
//     c->expo=-1;
//     lastC=c;
//     startA=a;
//     a=a->link;
//     b=b->link;
//     int done =0;
//     do
//     {
//         switch(COMPARE(a->expo,b->expo))
//         {
//             case 1:
//                 attach(a->coeff,a->expo,&lastC);
//                 a=a->link;
//                 break;
//             case 0:
//                 if(startA=a)
//                     done=1;
//                 int sum=a->coeff+b->coeff;
//                 if(sum)
//                 {
//                     attach(sum,a->expo,&lastC);
//                 }
//                 a=a->link;
//                 b=b->link;
//                 break;
//             case -1:
//                 attach(b->coeff,b->expo,&lastC);
//                 b=b->link;
//                 break;

//         }

//     }while(!done);
//     lastC->link=c;
//     return c;

// }
// void realPoly(polyptr *a)
// {
//     *a= (polyptr)malloc(sizeof(struct node));
//     (*a)->expo = -1;
//     polyptr temp;
//     temp=*a;
//     int n;
//     int expo;
//     int coeff;
//     printf("Enter number of terms:");
//     scanf("%d",&n);
//     for(int i=0;i<n;i++)
//     {
//         printf("Enter coeff and edxponent");
//         scanf("%d%d",&coeff,&expo);
//         attach(coeff,expo,&temp);
//     }
//     temp->link=(*a);
// }
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int expo;int coef;
    struct node* link;

};
typedef struct node* polyptr;
void attach(int coefficient,int exponent,polyptr* ptr)
{
    polyptr temp;
    temp = (polyptr)malloc(sizeof(struct node));
    temp->expo=exponent;
    temp->coef=coefficient;
    (*ptr)->link = temp;
    (*ptr)=temp;
}
void readPoly(polyptr *a)
{
    *a=(polyptr)malloc(sizeof(struct node));
    int expo,coef,n;
    polyptr temp;
    temp=(*a);
    printf("Enter the number of terms");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter coefficient");
        scanf("%d",&coef);
        printf("Enter exponenet");
        scanf("%d",&expo);
        attach(coef,expo,&temp);
    }
    temp->link=(*a);
}

