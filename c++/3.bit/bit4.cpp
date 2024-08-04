// generate all the subsets of a given array 
#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int arr[100]; 
for(int i = 0;i<n;i++)
{
    cin>>arr[i];
}
for(int i = 0; i< (1<<n); i++)
{
    for(int j=0;j<n ; j++) // generates a subset
    {
        if(i & (1<<j)) // gets the j bit of i
        {
            cout<<arr[j]<<"";
        }
    }cout<<endl;
}
return 0;
}