#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// int failure[20];
// void fail(char* pat)
// {
//     int i,j;
//     int n=strlen(pat);
//     failure[0]=-1;
//     for(j=1;j<n;j++)
//     {
//         i = failure[j-1];
//         while(pat[j]!=pat[i+1]&&i>0)
//         {
//             i=failure[i];
//         }   
//         if(pat[j]==pat[i+1])
//         {
//             failure[j]=i+1;
//         }
//         else
//         {
//             failure[j]=-1;
//         }
//     }
// }
int failure[20];
void fail(char* pat)
{
    int i,j,n;
    failure[0]=-1;
    n=strlen(pat);
    for(j=1;j<n;j++)//*************SHD START FROM J=1***********************//
    {
        i=failure[j-1];
        while(pat[j]!=pat[i+1]&&i>0)
        {
            i=failure[i];
        }
        if(pat[j]==pat[i+1])
        {
            failure[j]=i+1;
        }
        else
        {
            failure[j]=-1;
        }
    }
}
int match(char* str,char* pat)
{
    int i=0,j=0;//both the functions start with the declaration of i,j
    int lens=strlen(str);
    int lenp=strlen(pat);
    while(i<lens && j<lenp)
    {
        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)
        {
            i++;
        }
        else
        {
            j = failure[j-1]+1;//**************************************//
        }
    }
    return ((j==lenp)?(i-lenp):-1);//if j has reached and of length of patern means that we have found the pattern
}
// int match(char* str,char *pat)
// {
//     int i=0,j=0;
//     int lens=strlen(str);
//     int lenp=strlen(pat);
//     while(i<lens && j<lenp)
//     {
//         if(str[i]==pat[j])
//         {
//             i++;
//             j++;
//         }
//         else if(j==0)
//         {
//             i++;
//         }
//         else
//         {
//             j=failure[j-1]+1;
//         }
//     }
//     return ((j==lenp)?(i-lenp):-1);
// }
void main()
{
    int i;
    char str[30],sub[20];
    printf("\nEnter a string\n");
    scanf("%s",str);
    printf("\nEnter a substring\n");
    scanf("%s",sub);
    fail(sub);
    i=match(str,sub);
    if(i==-1)
    printf("\nNot found");
    else
    printf("\nFound at position %d",i+1);
}
// int failure[20];
// void fail(char *pat)
// {
//     int i,j,n=strlen(pat);
//     failure[0]=-1;
//     for(j=1;j<n;j++)
//     {
//         i=failure[j-1];
//         while(pat[j]!=pat[i+1]&&i>0)
//         {
//             i=failure[i];
//         }
//         if(pat[j]==pat[i+1])
//         {
//             failure[j]=i+1;
//         }
//         else
//         {
//             failure[j]=-1;
//         }
//     }

// }
// int match(char* str,char* pat)
// {
//     int lens=strlen(str);
//     int lenp=strlen(pat);
//     int i=0,j=0;
//     while(i<lens&&j<lenp)
//     {
//         if(str[i]==pat[j])//i is iterating through string,and j through pattern
//         {
//             i++;
//             j++;
//         }
//         else if(j==0)
//         {
//             i++;
//         }
//         else
//         {
//             j=failure[j-1]+1;//does not send j to the start of pat instead sends it to failure[j-1]+1;
//         }
//     }
//     return ((j==lenp)?(i-lenp):-1);
// }

int failure[20];
void fail(char *pat)
{
    int i,j,n;
    failure[0]=-1;
    n=strlen(pat);
    for(j=1;j<n;j++)
    {
        i=failure[j-1];
        while(pat[j]!=pat[i+1] && i>0)
        {
            i=failure[i];
        }
        if(pat[j]==pat[i+1])
        {
            failure[j]=i+1;
        }
        else
        {
            failure[j]=-1;
        }
    }
}
int match(char* str,char * pat)
{
    int i=0,j=0,lens,lenp;
    lens=strlen(str);
    lenp=strlen(pat);
    while(i<lens && j<lenp)
    {
        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)
        {
            i++;
        }
        else
        {
            j=failure[j-1]+1;
        }
    }
    return ((j==lenp)?(i-lenp):-1);
}