#include<stdio.h>
main()
{
    int i,n,j,temp=0,arr[50],counter = 1;
    printf("enter the length of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("array before sorting");
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
    while(counter<n)
    {
        for(i=0;i<n-counter;i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
            
        }
        counter++;
    }
    printf("\n");
    
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}