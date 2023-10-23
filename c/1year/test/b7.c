#include<stdio.h>
void main()
{
    int m,n,p,q,i,j,m1[50][50],m2[50][50],m3[100][100];
    printf("enter order of first matrix");
    scanf("%d%d",&m,&n);
    printf("enter order of second matrix");
    scanf("%d%d",&p,&q);
    if((m!=p) || (n!=q))
    {
        printf("addition not possible");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("enter %d%d element : ",i+1,j+1);
            scanf("%d",&m1[i][j]);
        }

    }
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("enter %d%d element : ",i+1,j+1);
            scanf("%d",&m2[i][j]);
        }
        
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            m3[i][j]=m1[i][j]+m2[i][j];
        }
        
    }
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",m3[i][j]);
        }
        printf("\n");
    }
    
    



    
}