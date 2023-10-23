#include<stdio.h>
void prime()
{
    int n,i,flag=0;
    printf("enter a number");
    scanf("%d",&n);
    for(i=2;i<(n/2);i++)
    {
        if((n%i)==0)
        {
            flag=1;
            printf("non prime");
            break;
        }
        if(flag==0)
        {
            printf("prime");
        }

    }
}
void main()
{
    prime();
}