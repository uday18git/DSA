// #include<stdio.h>
// void main()
// {
//     int high,low,mid,key,arr[50],i,n,flag=0;
    
//     printf("enter length");
//     scanf("%d",&n);
//     printf("enter array elements : ");
//     for(i=0;i<n;i++)
//     {
//         scanf("%d",&arr[i]);
//     }
//     printf("enter key");
//     scanf("%d",&key);
//     high = n-1;
//     low = 0;
    
//     while(low<=high)
//     {   
//         mid = (high+low)/2;
//         if(arr[mid]==key)
//         {
//             flag=1;
//             break;
//         }
//         else if(arr[mid]>key)
//         {
//             high = mid-1;
//         }
//         else if(arr[mid]<key)
//         {
//             low = mid+1;
//         }
//     }
//     if(flag==1)
//     {
//         printf("element found at %d",mid+1);
//     }
//     else{
//         printf("element not found");
//     }
// }
#include<stdio.h>
void main()
{
    int n,arr[100],key,high,low,mid,i,flag=0;
    printf("enter number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter key");
    scanf("%d",&key);
    high=n-1;
    low=0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]==key)
        {
            flag=1;
            break;
        }
        else if(arr[mid]>key)
        {
            high = mid-1;
        }
    }
}