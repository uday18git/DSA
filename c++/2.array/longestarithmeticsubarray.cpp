#include "bits/stdc++.h"
using namespace std;
int main(){
int n ;

cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int pd=arr[1]-arr[0],curr=2,m=2;
for(int i=1;i<n-1;i++)
{
   if( pd == arr[i+1] - arr[i])
   {
    curr++;
   }
   else{
   pd = arr[i+1] - arr[i];
   curr = 2;
   }
   m = max(m,curr);
  
}
cout<<m<<endl;
return 0;
}