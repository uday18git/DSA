#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    // the question boiled down to , largest subarray with atmost k zeros
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int curr_zeros=0;
        int last_zero=-1;
        int maxlen=0;
        int l=0;
        int r=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                if(last_zero==-1)
                {
                    last_zero=r;
                }
                curr_zeros++;
                // putting if condition with while condition inside of it with same conditions is considered a serious violation of the fifth amendment
                while(curr_zeros>k) // making the current window to have less or equal 0's than k
                {
                    if(nums[l]==0)
                    {
                        curr_zeros--;
                    }
                    l++;
                }
                
            }
            r++;
            maxlen=max(maxlen,r-l);
        }
        return maxlen;
    }
};