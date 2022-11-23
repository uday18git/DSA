#include "bits/stdc++.h" 
using namespace std;
int main(){
    // BRUTE FORCE
    // int n,sum=0,s;
    // cin>>n>>s;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         sum+=a[j];
    //         if(sum==s)
    //     {
    //         cout<<"found"<<endl;
    //         cout<<i<<j<<" ";
    //         break;
    //     }
    //     else
    //     {
    //         continue;
    //     }
    //     }
        
    // }
    
    //OPTIMISED
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int i=0,sum=0,j=0,st=-1,en=-1;
    while( j<n && sum + arr[j] <= s)
    {
        sum+=arr[j];
        j++;
    }
    if(sum == s)
    {
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    while(j<n)
    {
        sum+=arr[j];
        while(sum >s)
        {
            sum -= arr[i];
            i++;
        }
        if(sum==s)
        {
            st=i+1;
            en=j+1;
            break;
        }
        j++;
    
    }
cout<<i+1<<" "<<j+1<<endl;


return 0;
}