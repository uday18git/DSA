#include<iostream>
using namespace std;
// bit manipulation notes --->>>
// getbit 1 left shift to the position of bit we want to get then and operation
// setbit 1 left shift to the position of bit we want to set then or operation
// clearbit 1 left shift to the position of bit we want to clear then complement then and operation
// update bit we will make the position which we want to update to 0 then or with the val<<pos, its nothing but clear bit then set bit
// power of 2 -> if a number is power of 2 then n&(n-1) always =0
// count the number of 1's -> n = n&(n-1) if u do until it becomes 0 then we will get the number of 1's
// to generate all the subsets of a given array with size n  we will do a for loop from 0 till 2^n-1 , then with another for loop from 0 to n we will check which bit of the i value there is a 1 , that place we will print frm the array
// to find one unique number ,, xor all the numbers in a array , the 2 2 ones will cancel each other and only one number will be left that is the unique number
// to find two unique numbers , we will xor all numbers then xor of 2 unique numbers will come , see where 1 is there , and in the array which which number has 1 at that position , xor all those we will get one unique number then when we xor the first xor with the one unique number we will get the another unique number
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
    return ((n & ~(1<<pos)));
}
int clearbit(int n,int pos)
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
    int g = unsetbit(5,0);
    cout<<g<<endl;
    // int c = clearbit(10,1);
    // cout<<c<<endl;
    int b1=12;
    int b2=13;
    // cout<<(b1|b2);
    // int d = updatebit(10,3,0);
    // cout<<d<<endl;
return 0;
}