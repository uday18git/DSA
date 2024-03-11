class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        int len = 1;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (nums[i] > nums[j] && dp[i] == dp[j] + 1)
                {
                    cnt[i] += cnt[j];
                }
            }
            len = max(len, dp[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == len)
                ans += cnt[i]; //  we need total so we will find here
        }
        return ans;
    }
};