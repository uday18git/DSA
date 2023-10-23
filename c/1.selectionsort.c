#include <stdio.h>
void main()
{
    int i,j,temp, n,arr[90];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for( i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        
    }
    for(int i=0;i<n;i++)
        {
            printf("%d\t",arr[i]);
        }
}