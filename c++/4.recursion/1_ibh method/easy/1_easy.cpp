// I-B-H method easy
#include<iostream>
using namespace std;
int sumation(int n)
{
    if(n==1)
    {
        return 1;
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
    int fact = n*factorial(n-1);
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


void dec(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl;
    dec(n-1);
}
void inc(int n)
{
    
    if(n==0)
    {
        return;
    }
    n=n-1;
    inc(n);

    cout<<n<<endl;
    
}
int main(){
int n;
cin>>n;
inc(n);
return 0;
}
