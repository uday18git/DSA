// SIMILAR PROBLEM 1626 BEST TEAM WITH NO CONFLICTS

// instead of coordinate change , we can just take the indices

#include <bits/stdc++.h> 
using namespace std;

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1,1);
//         for(int i=n-2;i>=0;i--) // in each pass we are just checking if the curr i , can be a part of the curr max LIS
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(nums[i]<nums[j])
//                 {
//                     dp[i] = max(dp[j]+1,dp[i]);
//                 }
//             }
//         }
//         return *max_element(dp.begin(),dp.end());
//     }
// };

class Solution{
    public:
        int lis(vector<int>&nums)
        {
            int n=nums.size();
            vector<int>dp(n+1,1);
            for(int i=n-2;i>=0;i--)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(nums[i]<nums[j])
                    {
                        dp[i]=max(dp[i],dp[j]+1);
                    }
                }
            }
            return *max_element(dp.begin(),dp.end());
        }
};
int main()
{
    Solution obj;
    vector<int> lol = {1,0,3,4};
    cout<<obj.lis(lol);
    return 0;
}
// class Solution {
// public:
// int LIS(vector<int>& nums, int prev, int ind, std::vector<std::vector<int>>& memo) {
//         if (ind == nums.size()) {   
//             return 0;
//         }
        
//         if (memo[prev + 1][ind] != -1) {
//             return memo[prev + 1][ind];
//         }
        
//         int take = INT_MIN;
//         if (prev == -1 || nums[ind] > nums[prev]) {
//             take = LIS(nums, ind, ind + 1, memo); 
//         }
        
//         int donttake = LIS(nums, prev, ind + 1, memo);
//                 return memo[prev + 1][ind] = std::max(1 + take, donttake);
//     }
//     int lengthOfLIS(vector<int>& nums) {
        
//       int n = nums.size();
//         std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n, -1));
        
//         return LIS(nums, -1, 0, memo); 
//     }
// };

// in this we take 1e4 only and handle the -1e4 case seperately , passes
// BY THE WAY ADDING 1E4 EVERYWHERE IS CALLED COORDINATE CHANGE IN MEMOIZATION

// class Solution {
// public:
//     int solve(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp) {
//         if (ind == nums.size()) return 0;
//         if (dp[ind][prev + 1e4] != -1) return dp[ind][prev + 1e4];
//         int not_take = solve(nums, ind + 1, prev, dp);
//         int take = 0;
//         if (prev < nums[ind]) {
//             take = solve(nums, ind + 1, nums[ind], dp) + 1;
//         }
//         return dp[ind][prev + 1e4] = max(take, not_take);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1 && nums[0]==-1e4)return 1;
//         vector<vector<int>> dp(n + 1, vector<int>(2 * 1e4 + 1, -1));
//         return solve(nums, 0, -1e4, dp);
//     }
// };

// just because we are taking 2 extra spaces this doesnt satisfy and givees run time error
// class Solution {
// public:
//     int solve(vector<int>nums,int ind,int prev,vector<vector<int>>&dp)
//     {
//         if(ind==nums.size())return 0;
//         if(dp[ind][prev+1e4+1]!=-1)return dp[ind][prev+1e4+1];
//         int not_take  = solve(nums,ind+1,prev,dp);
//         int take = INT_MIN;
//         if(prev<nums[ind] || prev==-1e4-1 )
//         {
//             take = solve(nums,ind+1,nums[ind],dp)+1;
//         }
//         return dp[ind][prev+1e4+1] = max(take,not_take);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(2*(1e4)+3,-1));
//         return solve(nums,0,-1e4-1,dp);
//     }
// };

// plain recursive solution satisfies 22 testcases, not efficient

// class Solution {
// public:
// int solve(vector<int>nums,int ind,int prev)
// {
//     if(ind==nums.size())return 0;
//     int not_take  = solve(nums,ind+1,prev);
//     int take = INT_MIN;
//     if(prev<nums[ind] || prev==-1e5)
//     {
//         take = solve(nums,ind+1,nums[ind])+1;
//     }
//     return max(take,not_take);
// }
// int lengthOfLIS(vector<int>& nums) {
//     return solve(nums,0,-1e5);
// }
// };