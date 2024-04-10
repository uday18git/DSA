#include <bits/stdc++.h> 
using namespace std;
class Solution {
    long long countAlternatingSubarrays(vector<int> nums) {
        long long count=0;
        int left=0;
        for(int right=0;right<nums.size();right++)
        {
            if(right>0 && nums[right]==nums[right-1])
            {
                left=right;
            }
            count+=(right-left+1);
        }
        return count;
    }
}
// crazy solution