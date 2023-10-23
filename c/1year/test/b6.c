#include<stdio.h>
void main()
{
    
    int fib[10],n,i;
    fib[0]=0;
    fib[1]=1;
    
    printf("enter the fibonacci number");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
       
        
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d\t",fib[i]);
    }
}