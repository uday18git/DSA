#include<stdio.h>
void main()
{
    int n,i,temp;
    printf("\n Enter the number for multiplication table");
    scanf("%d",&n);
    for(i=1;i<=10;i++)
    {
        temp=n*i;
        printf(" %d * %d = %d \n ",i,n,temp);
    }
}