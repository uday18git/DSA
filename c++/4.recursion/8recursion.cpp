#include<iostream>
using namespace std;
int sumation(int n)
{
    if(n==0)
    {
        return 0;
    }
    int sum=n;
    sum += sumation(n-1);
    return sum;
}
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    int fact = n;
    fact *= factorial(n-1);
    return fact;
}
int fibonacci(int n)
{
    if(n<=0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    int fib;
    fib = fibonacci(n-1)+fibonacci(n-2);
    
    return fib;
}


int main(){
int a;
// a = sumation(5);
a = fibonacci(1);
cout<<a<<endl;
return 0;
}