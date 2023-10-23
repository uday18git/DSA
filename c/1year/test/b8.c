#include<stdio.h>
void main()
{
    int i,j,m1[50][50],m,n,t[50][50];
    printf("enter the order of matrix");
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("enter %d%d element : ",i+1,j+1);
            scanf("%d",&m1[i][j]);
        }

    }
   for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    {
        t[i][j]=m1[i][j];
    }
   }
   for(i=0;i<n;i++)
   {
    for(j=0;j<m;j++)
    {
        printf("%d\t",t[i][j]);
    }printf("\n");
   }
    
}