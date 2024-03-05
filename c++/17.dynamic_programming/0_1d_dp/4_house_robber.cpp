// maximum non adjacent subsequence sum
// memoization solution accepted in leet code
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> nums, vector<int> &dp)
    {

        if (n < 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int adj = solve(n - 1, nums, dp);
        int non_adj = solve(n - 2, nums, dp) + nums[n];
        return dp[n] = max(adj, non_adj);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        return solve(nums.size() - 1, nums, dp);
    }
};

// tabulation beats 100%

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if (n > 1)
        {
            dp[1] = max(nums[0], nums[1]);
        }
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }
        return dp[n - 1];
    }
};

// space optimization most optimal approach

// Function to solve the problem using dynamic programming
int solve(int n, vector<int> &arr)
{
    int prev = arr[0]; // Initialize the maximum sum ending at the previous element
    int prev2 = 0;     // Initialize the maximum sum ending two elements ago

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i]; // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2; // Add the maximum sum two elements ago

        int nonPick = 0 + prev; // Maximum sum if we don't pick the current element

        int cur_i = max(pick, nonPick); // Maximum sum ending at the current element
        prev2 = prev;                   // Update the maximum sum two elements ago
        prev = cur_i;                   // Update the maximum sum ending at the previous element
    }

    return prev; // Return the maximum sum
}

int main()
{
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();

    // Call the solve function and print the result
    cout << solve(n, arr);
    return 0;
}

// house robber 2 u just take 2 arrays one without the first element and one without the last element , the max of both gives the answer
