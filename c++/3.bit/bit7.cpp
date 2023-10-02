// program to find a unique number in an array where all numbers except one, are present thrice
// assuming there size is 64 bits we will make 64 length array 
// at 0th position of the array , put the number of numbers which has 1 at the 0th position

#include<iostream>
using namespace std;
bool getBit(int n,int pos)
{
    return ((n&(1<<pos))!=0);
}
int setBit(int n,int pos)
{
    return (n | (1<<pos));
}
int unique(int arr[],int n)
{
    int result=0;
    for(int i=0;i<64;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if(getBit(arr[j],i))
            {
                sum++;
            }   
        }
        if(sum%3!=0)
        {
            result = setBit(result,i);
        }
    }
    return result;
}

int main()
{
    int arr[]= { 1,2,3,2000,1,2,3,1,2,3};
    cout<<unique(arr,10)<<endl;
}