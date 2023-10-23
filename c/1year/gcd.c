#include<stdio.h>
void main()
{
    int n,m,p,q,rem,lcm,gcd;
    printf("enter 2 numbers");
    scanf("%d%d",&m,&n);
    p=n;
    q=m;
    do{
        rem=m%n;
        m=n;
        n=rem;

    }while(n!=0);
    gcd=m;
    lcm=(p*q)/gcd;
    printf("gcd=%d,lcm=%d",gcd,lcm);
}