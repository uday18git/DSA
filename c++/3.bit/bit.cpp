#include<iostream>
using namespace std;
int getbit(int n,int pos)
{
    return((n & (1<<pos))!=0);
}
int setbit(int n,int pos)
{
    return(n | (1<<pos));
}
int unsetbit(int n,int pos)
{
    return (~(n | (1<<pos)));
}
int clearbit(int n,int pos )
{
    int mask = ~(1<<pos);
    return(n & mask);
}
int updatebit(int n,int pos,int val)
{
    int mask = ~(1<<pos);
    n = n & mask;
    return(n | (val<<pos));
}


int main(){
    int g = getbit(12,1);
    cout<<g<<endl;
    // int c = clearbit(10,1);
    // cout<<c<<endl;
    // int d = updatebit(10,3,0);
    // cout<<d<<endl;
return 0;
}