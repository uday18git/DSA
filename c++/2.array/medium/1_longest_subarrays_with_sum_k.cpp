// what is a subarray? a contiguous part of an array
// [1, 2, 3, 4, 5] => [1, 2], [2, 3], [3, 4], [4, 5], [1, 2, 3], [2, 3, 4], [3, 4, 5], [1, 2, 3, 4], [2, 3, 4, 5], [1, 2, 3, 4, 5] are subarrays
// [1,3] would be a subsequence

// question , find the longest subarray with sum k in an array

// brute force will be to check all the subarrays

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    long long sum=0;
    int ans=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum==k)
            {
                ans=max(ans,j-i+1);
                continue;
            }
        }
        sum=0;
    }
    return ans;
}

// time complexity of this solution is O(n^2)

// more optimal solution will be

#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long ,int> mp;
    int n=a.size();
    int ans=0;
    long long currsum=0;
    for(int i=0;i<n;i++)
    {
        currsum+=a[i];
        if(currsum==k)
        {
            ans=max(ans,i+1);
        }
        mp[currsum]=i;
        if(mp.find(currsum-k)!=mp.end())
        {
            ans=max(ans,i-mp[currsum-k]);
        }
    }
    return ans;
}

// but the above code will fail in the case of 0's and negatives
// for example [2,0,0,3] k=3; , we will get 1 answer but we need 3 ,
// we have to look for the prefix sum as left as possible

#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long ,int> mp;
    int n=a.size();
    int ans=0;
    long long currsum=0;
    for(int i=0;i<n;i++)
    {
        currsum+=a[i];
        if(currsum==k)
        {
            ans=max(ans,i+1);
        }
        if(mp.find(currsum)==mp.end()) // difference is this
        {
            mp[currsum]=i;
        }
        long long rem = currsum-k;
        if(mp.find(rem)!=mp.end())
        {
            ans=max(ans,i-mp[currsum-k]);
        }
    }
    return ans;
}

// time complexity O(n*logn) if we are using ordered map , O(n) if we are using unordered map, but can go up to O(n^2) in worst case because of the hash collisions
// space complexity O(n) for the map
// the above approach is the optimal solution for arr containing both positive and negative numbers
// the above code still doesnt pass for just positive numbers
// most optimal approach is ->

// using two pointers
// keep moving right , if the sum is greater than k , then keep moving left until the sum is less than k
// time complexity O(2n) , space complexity O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int right=0;
    int left=0;
    int ans=0;
    int n=a.size();
    long long currsum=a[0];
    while(right<n)
    {
        while(left<=right && currsum>k)
        {
            currsum-=a[left];
            left++;   
        }
        if(currsum==k)
        {
            ans=max(ans,right-left+1);
        }   
        right++;
        if(right<n)currsum+=a[right];
    
    
    }
    return ans;
}