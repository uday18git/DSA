// longest subarray with sum k
// subarray -> contigous part of the array

// arr[] = 1,2,3,1,1,1,1,4,2,3
// brute force is to check all the subarrays

// brute force
#include <bits/stdc++.h> 
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();
    int ans=0;
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum==k)
            {
                ans=max(ans,j-i+1);
                continue;
            }
        }
    }
    return ans;
}
// longest subarray with sum k
// better approach is to use a hashmap
// concept of prefix sum
// in positive only 
// best approach is to use two pointers, if sum exceeds the required summ then do start++
// and if sum is less then do end++ yes , this is right approach
// optimal code for positive and negative 
// is better code for positive only
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& a, int k){
    int n = a.size();
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}