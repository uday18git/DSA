#include<stdio.h>
void main()
{
    int a,b,temp,*pa,*pb;
    printf("enetr two numbers");
    scanf("%d%d",&a,&b);
    pa=&a;
    pb=&b;
    temp=*pa;
    *pa=*pb;
    *pb=temp;
    printf("a=%d,b=%d",a,b);

}