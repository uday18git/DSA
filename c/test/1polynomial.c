#include <stdlib.h>
#include <stdio.h>
// #define COMPARE(x, y) ((x > y) ? 1 : ((x == y) ? 0 : -1))
// #define MAXTERMS 100
// typedef struct polynomial
// {
//     int coef;
//     int expo;
// } polynomial;
// polynomial terms[MAXTERMS];
// int avail = 0;
// void attach(int coefficient, int exponent)
// {
//     if (avail >= MAXTERMS)
//     {
//         fprintf(stderr, "Too many terms in the polynomail");
//         exit(0);
//     }
//     terms[avail].expo = exponent;
//     terms[avail++].coef = coefficient;
// }
// void padd(int startA, int finishA, int startB, int finishB, int startD, int finishD)
// {
//     float coefficient;
//     while (startA <= finishA && startB <= finishB)
//     {
//         switch (COMPARE(terms[startA].expo, terms[startB].expo))
//         {
//         case 1:
//             attach(terms[startA].coef, terms[startA].expo);
//             break;
//         case 0:
//             coefficient=terms[startA].coef+terms[startB].coef;
//             attach(coefficient,terms[startA].expo);
//             startA++;
//             startB++;
//             break;
//         case -1:
//             attach(terms[startB].coef,terms[startB].expo);
//             startB++;
//             break;
//         }

//     }
//     for(;startA<=finishA;startA++)
//     {
//         attach(terms[startA].coef,terms[startA].expo);
//     }
//     for(;startB<=finishB;startB++)
//     {
//         attach(terms[startB].coef,terms[startB].expo);
//     }
// }
// void main()
// {
//     int expo,coef,t1,t2,i;
//     printf("Enter the number of terms in first polynomial");
//     scanf("%d",&t1);
//     for(i=0;i<t1;i++)
//     {
//         printf("Enter the coeff (%d)",i+1);
//         scanf("%d",&coef);
//         printf("Enter the expo (%d)",i+1);
//         scanf("%d",&expo);
//         attach(coef,expo);
//     }
//     printf("Enter the number of terms in second polynomial");
//     scanf("%d",&t2);
//     for(i=0;i<t2;i++)
//     {
//         printf("Enter the coeff (%d)",i+1);
//         scanf("%d",&coef);
//         printf("Enter the expo (%d)",i+1);
//         scanf("%d",&expo);
//         attach(coef,expo);

//     }
//     padd(0,t1-1,t1,t1+t2-1,avail,0);
//     for(i=t1+t2;i<avail;i++)
//     {
//         printf("%d",terms[i].coef);
//         printf("X^");
//         printf("%d",terms[i].expo);
//         if(i<avail-1)
//         {
//             printf("+");
//         }
//         else
//         {
//             exit(0);
//         }
//     }
// }
// #define COMPARE(x,y)((x>y)?1:((x==y)?0:-1))
// #define MAX_TERMS 100
// typedef struct polynomial
// {
//     int coef;
//     int expon;

// }polynomial;
// polynomial terms[MAX_TERMS];
// int avail = 0;
// void attach(int coefficient,int exponent)
// {
//     if(avail>=MAX_TERMS)
//     {
//         fprintf(stderr,"too many terms in the polynomial");
//         exit(1);
//     }
//     else{
//         terms[avail].coef = coefficient;
//         terms[avail++].expon = exponent;
//     }
// }
// void padd(int startA, int finishA, int startB, int finishB, int startD,int finishD)
// {
//     float coefficient;
//     startD = avail;
//     while (startA <= finishA && startB <= finishB)
//     {
//         switch (COMPARE(terms[startA].expon, terms[startB].expon))
//         {
//         case -1:
//             attach(terms[startB].coef, terms[startB].expon);
//             startB++;
//             break;
//         case 0:
//             coefficient = terms[startA].coef+terms[startB].coef;
//             if(coefficient)
//                 attach(coefficient,terms[startA].expon);
//                 startA++;
//                 startB++;
//                 break;
//         case 1:
//             attach(terms[startA].coef,terms[startA].expon);
//             startA++;
//             break;
//         }
//     }
//     for(;startA<=finishA;startA++)
//        attach(terms[startA].coef,terms[startA].expon);
//     for(;startB<=finishB;startB++)
//        attach(terms[startB].coef,terms[startB].expon);
//        finishD = avail-1;
// }

// void main()
// {
//     int t1,t2,i,coef,expon;
//     printf("\n Enter the total number of terms in the first polynomial ");
//     scanf("%d",&t1);
//     printf("enter the coefficient and exponent \n");
//     for(i=0;i<t1;i++)
//     {
//         printf("enter the coeficient (%d):",i+1);
//         scanf("%d",&coef);
//         printf("Enter the exponent(%d)",i+1);
//         scanf("%d",&expon);
//         attach(coef,expon);

//     }
//     printf("\n Enter terms in 2nd polynomial ");
//     scanf("%d",&t2);
//     printf("enter the exponent and coefficient");
//     for(i=0;i<t2;i++)
//     {
//         printf("enter the coeficient (%d):",i+1);
//         scanf("%d",&coef);
//         printf("Enter the exponent(%d)",i+1);
//         scanf("%d",&expon);
//         attach(coef,expon);

//     }
//     printf(" The addition of two polynomials is\n");
//     padd(0,t1-1,t1,t1+t2-1,avail,0);
//     for(i=(t1+t2);i<avail;i++)
//     {
//         printf("%d",terms[i].coef);
//         printf("(X^%d)",terms[i].expon);
//         if(i<avail-1)
//         {
//             printf("+");
//         }
//         else
//         {
//             exit(0);
//         }
//     }
// }
#define COMPARE(x, y) ((x > y) ? 1 : ((x == y) ? 0 : -1))
#define MAXTERMS 100
int avail = 0;
typedef struct
{
    int expo;
    int coef;
} polynomial;
polynomial terms[100];
void attach(int coefficient, int exponent)
{
    if (avail >= MAXTERMS)
    {
        fprintf(stderr, "Too many elements in polynomial");
        exit(0);
    }
    else
    {
        terms[avail].coef = coefficient;
        terms[avail++].expo = exponent;
    }
}
void padd(int startA, int finishA, int startB, int finishB, int startD, int finishD)
{
    float coefficient;
    while (startA <= finishA && startB <= finishB)
    {
        switch (COMPARE(terms[startA].expo, terms[startB].expo))
        {
        case 1:
            attach(terms[startA].coef, terms[startA].expo);
            startA++;
            break;
        case 0:
            coefficient = terms[startA].coef + terms[startB].coef;
            attach(coefficient, terms[startA].expo);
            startA++;
            startB++;
            break;
        case -1:
            attach(terms[startB].coef, terms[startB].expo);
            startB++;
            break;
        }
    }
}
void main()
{
    int i,t2,t1,expo,coef;
    printf("Enter the number of terms in first polynomial");
    scanf("%d",&t1);
    for(i=0;i<t1;i++)
    {
        printf("enter the coefficient of (%d) term: ",i+1);
        scanf("%d",&coef);
        printf("enter the exponent of (%d) term: ",i+1);
        scanf("%d",&expo);
        attach(coef,expo);
    }
    printf("Enter the number of terms in first polynomial");
    scanf("%d",&t2);
    for(i=0;i<t2;i++)
    {
        printf("enter the coefficient of (%d) term: ",i+1);
        scanf("%d",&coef);
        printf("enter the exponent of (%d) term: ",i+1);
        scanf("%d",&expo);
        attach(coef,expo);
    }
    padd(0,t1-1,t1,t1+t2-1,avail,0);
    for( i=t1+t2;i<avail;i++)
    {
        printf("%d",terms[i].coef);
        printf("X^%d",terms[i].expo);
        printf("+");
    }
}