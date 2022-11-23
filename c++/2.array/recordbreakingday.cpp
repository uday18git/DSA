#include "bits/stdc++.h"
 
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    int m=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m && ((i==n-1)||(arr[i]>arr[i+1])) )
        {
            m = arr[i];
            ans++;
        }
        

    }
    cout<<ans;

return 0;
}