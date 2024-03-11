// SIMILAR PROBLEM 1626 BEST TEAM WITH NO CONFLICTS

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