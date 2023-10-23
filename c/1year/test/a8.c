#include<stdio.h>
void main()
{
    int key,arr[50],i,n,flag=0;
    printf("enter length of array");
    scanf("%d",&n);
    printf("enter elements");
    for(i=0;i<n;i++)
    {
    scanf("%d",&
    arr[i]);

    }
    printf("enter key");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            flag=1;
            printf("element found at : %d",i+1);
            break;
        }
    }
    if(flag==0)
    {
        printf("element not found");
    }
}