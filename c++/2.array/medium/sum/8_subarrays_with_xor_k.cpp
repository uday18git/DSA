// optimized,  
// same as the above question
#include<bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    map<int,int> m;
    m[0]=1;
    int n=a.size();
    int xr=0,x,count=0;
    for(int i=0;i<n;i++)
    {
        xr = xr^a[i];
        x=xr^b; //x is the number which we have to xor to xr so that we get b
        count+=m[x];
        m[xr]++;
    }
    return count;
}

// brute
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        int currxor=0;
        for(int j=i;j<n;j++)
        {
            currxor = currxor^a[j];
            if(currxor==b)
            {
                count++;
            }
        }
    }
    return count;
}



// similar question 

// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/description/
// shortest they are asking


// brute force 
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int curror=0;
            // if(nums[i]>=k)
            // {
            //     return 1;
            // }
            for(int j=i;j<n;j++)
            {
                curror = curror | nums[j];
                if(curror>=k)
                {
                    ans= min(ans,j-i+1);
                }
            }
        }
        return (ans==INT_MAX) ? -1: ans;
    } 
};