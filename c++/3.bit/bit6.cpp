// find two unique numbers using bit manipulation
#include<iostream>
using namespace std;
int getbit(int n,int pos)
{
    return((n & (1<<pos))!=0);
}
void uniq2(int arr[],int n)
{
    int totalxor=0;
    for(int i=0;i<n;i++)
    {
        totalxor = totalxor^arr[i] ;
    }
    int no=0,pos=0;
    while(no!=1)
    {
        no = totalxor & (1<<pos);
        pos++; 
    }
    int newxor = 0;
    for(int i=0; i<n;i++)
    {
        if((arr[i] & (1<<(pos-1)))!=0)
        {
            newxor = newxor^arr[i];
        }
    }
    int secondxor = 0;
    for(int i=0; i<n;i++)
    {
        if(!(getbit(arr[i],pos-1)))
        {
            secondxor = secondxor^arr[i];
        }
    }
    cout<<newxor<<" "<<secondxor<<endl;
}



int main(){
int arr[] = {1,2,3,4,1,2,3,5};
uniq2(arr,8);
return 0;
}