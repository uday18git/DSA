#include<stdio.h>
void main()
{
    int flag=0,x,rem=0,rev=0,temp;
    
    printf("enter a number");
    scanf("%d",&x);
    temp=x;
    while(x>0)
    {
        rem=x%10;
        rev=rev*10+rem;
        x=x/10;

    }
    if(rev==temp)
    {
        printf("enter number is palindrome");
    }
    else{
        printf("no");
    }
}