#include<string.h>
#include<stdio.h>
void main()
{
    int i,j,len,flag=0;
    char s1[40],s2[40];
    gets(s1);
    len=strlen(s1);
    for(i=0,j=len-1;j>=0;i++,j--)
    {
        s2[i]=s1[j];
    }
    s2[len]='\0';
    printf("reversed string : ");
    puts(s2);
    for(i=0;i<len;i++)
    {
        if(s1[i]!=s2[i])
        {
            flag=1;
            printf("string is not palindrome");
            break;
        }
    }
    if(flag==0)
    {
        printf("string is a palindrome");
    }
    
}