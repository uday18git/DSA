// the below solution gets accepted omg

// this is pure recursion, there is another approach where we do dp and backtrack in that to get the answers
// we will see that when we study dp
class Solution
{
public:
    void f(int idx, int target, vector<int> candidates, vector<int> curr, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (idx == candidates.size())
            return;
        f(idx + 1, target, candidates, curr, ans);
        if (target - candidates[idx] >= 0)
        {
            curr.push_back(candidates[idx]);
            f(idx, target - candidates[idx], candidates, curr, ans);
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        f(0, target, candidates, curr, ans);
        return ans;
    }
};


// long solution

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>&candidates , int target) {
        int n = candidates.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        vector<vector<int>> ans;
        vector<int> current;

        // Initialize the dp array
        for (int i = 0; i < target + 1; i++) {
            dp[0][i] = false;
        }
        for (int i = 0; i < n + 1; i++) {
            dp[i][0] = true;
        }

        // Populate the dp array
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < target + 1; j++) {
                if (candidates[i - 1] <= j) {
                    dp[i][j] = dp[i][j - candidates[i - 1]] || dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Backtrack to find combinations
        generateCombinations(candidates, target, n, dp, current, ans);
        return ans;
    }

    void generateCombinations(vector<int>& candidates, int target, int n, vector<vector<bool>>& dp, vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        
        if (n <= 0 || target < 0 || !dp[n][target]) {
            return;
        }

        // Exclude the current candidate
        generateCombinations(candidates, target, n - 1, dp, current, ans);

        // Include the current candidate and continue generating combinations
        current.push_back(candidates[n - 1]);
        generateCombinations(candidates, target - candidates[n - 1], n, dp, current, ans);
        current.pop_back(); // Backtrack by removing the last added candidate
    }
};