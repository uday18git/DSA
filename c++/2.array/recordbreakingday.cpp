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
    int ans,currmax= INT_MIN;
    for(int i=0;i<n-1;i++)
    {
        
        if(arr[i]>arr[i+1] && arr[i]>currmax)
        {
            ans = arr[i];
        }
        currmax = max(currmax,arr[i]);
    }
    cout<<ans;

return 0;
}