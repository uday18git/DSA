#include<iostream>
using namespace std;
int unique(int arr[],int n)
{
    int xorsum=0;
    for(int i = 0 ; i < n;i++)
    {
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}


int main(){

return 0;
}