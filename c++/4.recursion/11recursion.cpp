#include<iostream>
using namespace std;
int foccurance(int arr[],int n,int i,int key)
{
   
    if(i==n)
    {
        return -1;
    }
     if(arr[i]==key)
    {
        return i;
    }


    return foccurance( arr,n, i+1,key);
    
}
int loccurance(int arr[],int n,int i,int key)
{
   
    if(i==0)
    {
        return -1;
    }
     if(arr[i]==key)
    {
        return i;
    }


    return loccurance( arr,n, i-1,key);
    
}




int main(){
int arr[] = {10,20,30,20,19,30,28};
int f = foccurance(arr,7,0,30);
int l = loccurance(arr,7,6,30);

cout<<f<<endl;
cout<<l<<endl;

return 0;
}