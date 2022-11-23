#include "bits/stdc++.h"
 
using namespace std;
int main(){
int n;
cin>>n;
int N = 1e6+1;
bool check[N];
int a[n];
for(int i=0;i<N;i++)
{
    check[i]=false;
} 
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int j=0;
while(j<n)
{
    if(a[j]>=0)
    {
        check[a[j]]=true;
    }

    j++;
}
for(int i=0;i<n;i++)
{
    if(check[i]== false)
    {
        cout<<i<<endl;
        break;
    }
}

return 0;
}