class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(currsum<0)
            {
                currsum=0;
            }
            currsum+=nums[i];
            ans=max(currsum,ans);
        }
        return ans;
    }
};