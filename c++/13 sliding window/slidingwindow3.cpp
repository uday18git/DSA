//MAX SUM of a SUBARRAY with sum < x 
#include <bits/stdc++.h>
using namespace std;
int main(){
    int sum=0;
    int ans;
    int n,k,x;cin>>n>>k>>x;//n is the size of array k is window size
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    for(int i=0;i<k;i++)
    {  
        sum+=a[i];
    }
    if(sum<x)ans=sum;
    for(int i=k;i<n;i++)
    {
        sum = sum-a[i-k];
        sum+=a[i];
        if(sum<x)ans = min(ans,sum);
    }
cout<<ans;
return 0;
}