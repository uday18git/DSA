#include<stdio.h>
void main()
{
    int count[50],i,max=0;
    for(i=0;i<12;i++)
    {
        printf("\n Enter the covid count in %d th month of the year ",i+1);
        scanf("%d",&count[i]);
       
    }
    for(i=1;i<12;i++)
    {
         if(count[i]>count[i-1])
        {
            max=count[i];
        }
    }
     if(count[0]>max){
        printf("the max number of covid count is %d",count[0]);

     }
     else
     {
        printf("the max number of covid count is %d",max);
     }
}