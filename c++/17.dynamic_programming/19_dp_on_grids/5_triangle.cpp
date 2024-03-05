// recursive solution passed 42/44

// memoized passed all test cases

class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (i >= triangle.size() || j >= triangle[i].size()) // kinda unneccesary
            return 0;
        if (i == triangle.size() - 1)
            return triangle[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];
        int same_col = triangle[i][j] + solve(i + 1, j, triangle, dp);
        int next_col = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);
        return dp[i][j] = min(same_col, next_col);
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size(), m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, triangle, dp);
    }
};


