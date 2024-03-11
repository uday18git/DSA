class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n); // stores the previous element that was added
        int maxIndex=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            hash[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    hash[i] = j;
                }
            }
            if(dp[i]>dp[maxIndex])
            {
                maxIndex=i;
            }
        }
        vector<int> ans;
        while(maxIndex!=hash[maxIndex])
        {
            ans.push_back(nums[maxIndex]);
            maxIndex = hash[maxIndex];
        }
        ans.push_back(nums[maxIndex]);
        reverse(ans.begin(),ans.end());
        return ans;
    
    }
};