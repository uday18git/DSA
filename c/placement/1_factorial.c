// recursive factorial function

#include <stdio.h>
int factorial(int num)
{
    if(num==1)
    {
        return num;
    }
    int fact = num*factorial(num-1);
    return fact;
}
void main()
{
    int fact;
    scanf("%d",&fact);
    int ans = factorial(fact);
    printf("Factorial of the number is %d",ans);
    return 0;
}