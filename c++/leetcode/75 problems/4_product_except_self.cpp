// https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans={1};
        int postfix=1;
        for(int i=1;i<nums.size();i++)
        {
            ans.push_back(ans[i-1]*nums[i-1]); 
        }
        // till this point we have calculated the prefix sums
        for(int i=ans.size()-2;i>=0;i--)
        {
            postfix*=nums[i+1];
            ans[i]*= postfix;
        }
        return ans;
    }
};
