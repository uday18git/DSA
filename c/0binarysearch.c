#include<stdio.h>
int RecursiveBinary(int arr[],int high,int low,int key)
{
    int mid = (high+low)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        return RecursiveBinary(arr,mid-1,low,key);
    }
    else
    {
        return RecursiveBinary(arr,high,mid+1,key);
    }
    return -1;
}
void main()
{
    int n,i,ans,key;
    printf("Enter the key");
    scanf("%d",&key);
    int arr[50];
    printf("Enter the array length");
    scanf("%d",&n);
    printf("Enter the array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    ans= RecursiveBinary(arr,n,0,key);
    printf("key found at (%d)",ans);

}