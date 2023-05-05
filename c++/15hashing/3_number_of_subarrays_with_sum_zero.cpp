// to find the number of subarrays with sum 0
// brute force ->  go over all the subarrays and compute sum
// O(n^2) because n + n-1 + n-2 + n-3 + .... + 1 = n(n+1)/2
// optimized soln hashing
// 1. compute prefix sum and map prefix sum to a map
// suppose array = {1,-1,1,-1}
// prefix sum = {1,0,1,0} it is the sum till that element
// main idea -> for an array of prefix sum if we find two elements with same value then the sum of elements between them is 0
// for every key choose 2 values from all the occurance of particular prefix sum (MC2)
// special case -> if prefix sum is 0 then we can choose any also include them in the count.
// In general, if there are m occurrences of a particular prefix sum, 
// there are m*(m-1)/2 possible pairs of indices (i, j) such that i < j and the subarray a[i..j] has a sum of zero.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map<int,int> count;
    int prefix_sum=0;
    for(int i=0;i<n;i++)
    {
        prefix_sum+=a[i];
        count[prefix_sum]++;
    }
    int ans=0;
    map<int,int> :: iterator it;
    for(it=count.begin();it!=count.end();it++)
    {
        int m=it->second;
        ans+=m*(m-1)/2;
        if(it->first==0)
        {
            ans+=m;
        }

    }
    cout<<ans<<endl;

    return 0;
}