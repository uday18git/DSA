#include<stdio.h>
#include<string.h>
void main()
{
    int n,i;
    char kids_care[100][100],key[100],name[100],flag=0;
    printf("enter number of kids care");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter %d th string",i+1);
        scanf("%s",kids_care[i]);
    }
    printf("enter kids care to search");
    scanf("%s",key);
    for(i=0;i<n;i++)
    {
        if(!(strcmp(kids_care[i],key)))
        {
            flag=1;
            printf("kids care found at %d",i+1);
            break;
        }
    }
    if(flag==0)
    {
        printf("kids care not found");
    }



}