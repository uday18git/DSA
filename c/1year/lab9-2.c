#include<stdio.h>
void main(){
    int m[50][50],i,j,r,c;
    printf("enter rows and columns:");
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(i==j)
            {
                m[i][j]=0;
            }
            else{
                printf("Enter the %d %d element :",i+1,j+1);
                scanf("%d",&m[i][j]);
            }
        }
    }
    printf("Resulting matrix is\n ");
    for(i=0;i<r;i++)
    {
        for ( j = 0; j<c ; j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}