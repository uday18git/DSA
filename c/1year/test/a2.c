#include<stdio.h>
void main()
{
   int a,b,c;
   printf("enter 3 numbers");
   scanf("%d%d%d",&a,&b,&c);
   (a>b)?((a>c)?printf("a is the greatest"):printf("c is the greatest")):(b>c)?printf("b is the greatest"):printf("c is the greatest");
    
} 