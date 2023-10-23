#include<stdio.h>
void main()
{
    int g,a,b,c;
    printf("enter 3 numbers");
    scanf("%d%d%d",&a,&b,&c);
    ((a>b)?((a>c)?printf("%d is greatest",a):printf("%d is greatest",c)):((b>c)?printf("%d is greatest",b):printf("%d is greatest",c)));


}