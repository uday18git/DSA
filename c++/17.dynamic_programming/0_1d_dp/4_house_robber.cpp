// maximum non adjacent subsequence sum
// memoization solution accepted in leet code
#include <bits/stdc++.h>
using namespace std;
// here we are defining solve(n) to give the maximum sum from 0 till n
// recursive soln passes 48/70 test cases
// class Solution {
// public:
//     int solve(int i,vector<int> nums)
//     {
//         if(i<0)
//         {
//             return 0;
//         }
//         int pick = solve(i-2,nums)+nums[i];
//         int not_pick = solve(i-1,nums);
//         return max(pick,not_pick);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         return solve(n-1,nums);
//     }
// };

// memoization
class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp)
    {
        if(i<0)
        {
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int pick = solve(i-2,nums,dp)+nums[i];
        int not_pick = solve(i-1,nums,dp);
        return dp[i] = max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
};

// passes 40/70
// doesnt pass test ccases like [2,1,1,2]
// the below soln only takes into account starting from first element and the second element and all the adjcaent elements from there on
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         int one=0;
//         int two=0;
//         for(int i=0;i<n;i+=2)
//         {
//             one+=nums[i];
//         }
//         for(int i=1;i<n;i+=2)
//         {
//             two+=nums[i];
//         }
//         return max(one,two);

//     }
// };

// tabulation
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n);
//         dp[0] = nums[0];
//         if(n>1)
//         {
//             dp[1] = max(nums[0],nums[1]);
//         }
//         for(int i=2;i<n;i++)
//         {
//             dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
//         }
//         return dp[n-1];
//     }
// };

// space optimization most optimal approach
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0 , rob2 =0;
        for(int i:nums)
        {
            int temp = max(i+rob1,rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
};

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();

    // Call the solve function and print the result
    cout << solve(n, arr);
    return 0;
}

// house robber 2 u just take 2 arrays one without the first element and one without the last element , the max of both gives the answer
