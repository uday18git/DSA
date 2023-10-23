#include<stdio.h>
void main()
{
    int i,n;
    char planet[200][200],*pa;
    
    printf("enter the value of n : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   
        printf("enter planet name : ");
        scanf("%s",planet[i]);
    }
    for(i=0;i<n;i++)
    {   
        pa = planet[i];
        printf("Name of %d planet : ",i+1);
        for(i=0;*pa!='\0';i++)
        {
        printf("%c",*(pa));
        pa++;
        }
        printf("\n");
    }
}