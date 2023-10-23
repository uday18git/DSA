#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,len,flag=0;
    char s1[50];
    printf("enter a string ");
    gets(s1);
    len = strlen(s1);
    for(i=0,j=len-1;i<=len-1,j>=0;i++,j--)
    {
        if(s1[i]!=s1[j])
        {
            flag=1;
            printf("no");
            break;

        }
        
    }
    if(flag==0)
        {
            printf("palindrome");
        }

}