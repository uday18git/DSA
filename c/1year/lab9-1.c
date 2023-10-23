#include<stdio.h>
void main()
{
    int m[50][50],i,j,row_sum,col_sum,row,col;
    printf("enter rows and columns");
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
    {
        for ( j = 0; j < col; j++)
        {
            scanf("%d",&m[i][j]);
        }
        
    }
    for(i=0;i<row;i++)
    {
        for ( j = 0; j < col; j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            row_sum+=m[i][j];
        }
        printf("sum of %d row is %d",i+1,row_sum);
        row_sum=0;
    }
    
}