#include<stdio.h>
void main()
// {
//     int n,temp,rev=0,rem=0;
//     printf("enter n");
//     scanf("%d",&n);
//     temp=n;
//     while(n!=0)
//     {
//         rem=n%10;
//         rev=rev*10+rem;
//         n=n/10;
//     }
//     if(rev==temp){
//         printf("palindrome");
//     }
//     else{
//         printf("not a palindrome");
//     }

// }
{
    int n,rev=0,rem=0,temp=0;
    printf("enter a number");
    scanf("%d",&n);
    temp = n;
    while(n!=0)
    {
        rem = n/10;
        rev = rev*10 + rem;
        n=n/10;
    }
    if(rev==temp)
    {
        printf("plaindrome");
    }
    else
    {
        printf("not palindrome");
    }
}