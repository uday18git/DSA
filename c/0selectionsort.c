#include<stdio.h>
void main()
{
    int arr[50],i,j,n,temp;
    printf("Enter the array length");
    scanf("%d",&n);
    printf("Enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("Sorted array");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}