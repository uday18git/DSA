#include<stdio.h>
void main()
{
    int row,col,i,j,m[50][50],sum=0,row_sum=0,col_sum=0;
    printf("enter rows and colums");
    scanf("%d%d",&row,&col);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++){
            printf("enter the %d %d element",i+1,j+1);
            scanf("%d",&m[i][j]);
            sum+=m[i][j];
        }
    }
    printf("the sum of all elements is %d \n",sum);
    printf("the given matrix is \n");
    
    for(i=0;i<row;i++)
    {
        for ( j = 0; j<col ; j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++){
        for(j=0;j<col;j++)
        {
            row_sum+=m[i][j];
        }
        printf("the sum of %d row is %d \n",i+1,row_sum);
        row_sum=0;
    }
    for(i=0;i<col;i++){
        for(j=0;j<row;j++)
        {
            col_sum+=m[j][i];
        }
        printf("the sum of %d col is %d \n",i+1,col_sum);
        col_sum=0;
    }
    
    

}