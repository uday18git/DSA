#include<string.h>
#include<stdio.h>
void main()
{
    int i,flag=0;
    char s1[50],s2[50];
    printf("enter a string");
    scanf("%s",s1);
    printf("enter a string");
    scanf("%s",s2);
    for(i=0;i<=strlen(s2);i++)
    {
        if(s1[i]==s2[i])
        {
            flag=0;
        }
        else{
            flag=1;
        }
    }
    if(flag==1)
    {
        printf("strings are not same");
    }
    else{
        printf("strings are same");
    }
}