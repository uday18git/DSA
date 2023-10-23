#include<stdio.h>
void main()
{   
    int n;
    int a,b,c;
    printf("enter charater");
    scanf("%d",&n);
    printf("enter 2 numbers");
    scanf("%d%d",&a,&b);
    switch(n)
    {
        case 1:
            c=a+b;
            printf("%d",c);
            break;
        case 2:
            c=a*b;
            printf("%d",c);
            break;
    }
}