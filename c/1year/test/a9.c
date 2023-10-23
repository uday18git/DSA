// #include<stdio.h>
// #include<string.h>
// void main()
// {
//     char s1[100],s2[100];
//     int i,j,len1,len2;
//     printf("enter string1");
//     gets(s1);
//     printf("enter string2");
//     gets(s2);
//     len1=strlen(s1);
//     len2=strlen(s2);
//     for(i=0,j=len1;s2[i]!='\0';i++,j++)
//     {
//         s1[j]=s2[i];
//     }
//     s1[len1+len2]='\0';
//     printf("\ncombined string : ");
//     puts(s1);

// }
#include<stdio.h>
#include<string.h>
void main()
{
    char s1[100],s2[100];
    int i,j,len1,len2;
    printf("enter a string");
    gets(s1);
    printf("enter a string");
    gets(s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    for(i=0,j=len1;s2[i]!='\0';i++,j++)
    {
        s1[j]=s2[i];
    }

}