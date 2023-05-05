// problem -> you are given an array with n elements , calculate the minimum sum of k consecutive elements
// example -> arr = {-2,10,1,3,2,-1,4,5} 
// calculate various sums -> 9,14,6,4,5,8 when k=3
// brute force -> calculate all the sums and find the minimum one .. starting from every j=i compute sum of k elements and maintain the minimum
// O(N*K)
// optimized -> sliding window technique
#include <bits/stdc++.h> 
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=a[i];
    }
    int min_sum=sum;
    for(int i=k;i<n;i++)
    {
        sum+=a[i]-a[i-k];
        min_sum=min(min_sum,sum);
    }
    cout<<min_sum<<endl;
return 0;
}