#include<stdio.h>
void main()
{
    int n,i,odd_sum=0,even_sum=0;
    printf("enter a number");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        if(i%2==0)
        {
            even_sum+=i;
        }
        else{
            odd_sum+=i;
        }
    }
    printf("odd sum is %d and even sum is %d",odd_sum,even_sum);
    
}