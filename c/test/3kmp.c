// a b c d a b c a b c d f (i)
// a b c d f (J)
// if i and j are not same move i till they r same
// if they are same move i and j both if theres a mismatch it should again come back and check by comparing i+1 and j again
// this is the disadvantage of naive algorithm O(MN)
//  suppose a a a a a b (i)
//  a a a b (j) after comparing the first 3 alphabets j need not come back again it just needs it check whether next char is b or not 
// so naive algo is not studying the pattern
// kmp algo studies the pattern
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int failure[20];
void fail(char* pat)
{   //failure array -1 -1 0 1 
    int i,j,n;
    failure[0]=0;
    n=strlen(pat);
    for(i=1;i<n;i++)//*************SHD START FROM J=1 ***********************//
    {
        j=failure[i-1];
        while(pat[i]!=pat[j]&&j>0)//a b a b d
        {
            j=failure[j-1];
        }
        if(pat[i]==pat[j+1]) //j is moving throughout the pattern and i is just checking for patterns
        {
            failure[i]=j+1;
        }
        else
        {
            failure[i]=-1;
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
        if(str[i]==pat[j])//i is iterating through string,and j through pattern
        {
            i++;
            j++;
        }
        else if(j==0)// j(pattern) is still on first one and not matching means simply i++ we should do 
        {
            i++;
        }
        else
        {
            j = failure[j-1]+1;//does not send j to the start of pat instead sends it to failure[j-1]+1;
        }
    }
    return ((j==lenp)?(i-lenp):-1);//if j has reached length of patern means that we have found the pattern
}

void main()
{
    int i;
    char str[30],sub[20];
    printf("\nEnter a string\n");
    scanf("%s",str);// a b a b c a b c a b a b a b d
    printf("\nEnter a substring\n");
    scanf("%s",sub);//a b a b d
    fail(sub);
    i=match(str,sub);
    if(i==-1)
    printf("\nNot found");
    else
    printf("\nFound at position %d",i+1);
}

int failure[20];
void fail(char* pat)
{
    failure[0]=-1;
    int i,j,n;
    n=strlen(pat);
    for(j=1;j<n;j++)
    {
        i=failure[j-1];
        while (i>0&& pat[i+1]!=pat[j])
        {
            i=failure[i];
        }
        if(pat[i+1]==pat[j])
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
    int lens=strlen(str);
    int lenp=strlen(pat);
    int i=0,j=0;
    while(i<lens&& j<lenp)
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
}
