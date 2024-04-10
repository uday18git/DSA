// write c code to find the fibonacci series
#include<stdio.h>
void main()
{
    int fib;
    int arr[10];
    int i=0;
    scanf("%d",&fib);
    arr[0]=1;
    arr[1]=1;
    if(fib<=1)
    {
        printf("%d",arr[fib]);
    }
    for(i=2;i<=fib;i++)    
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    printf("%d",arr[fib]);
}

