// brute force is to check all subarrays
// better approach is to keep track of min product and max product and multiply the current one with
#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = 1;
        int maxProd = 1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            int temp = minProd;
            minProd = min(nums[i],min(minProd*nums[i],maxProd*nums[i]));
            maxProd = max(nums[i],max(maxProd*nums[i],temp*nums[i]));
            ans=max(ans,maxProd);
        }
        return ans;
    }
};