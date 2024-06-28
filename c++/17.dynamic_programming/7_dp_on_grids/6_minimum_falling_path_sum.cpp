// here i did not consider that answer can come out of the non minimum element from the first row
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> matrix)
    {
        if (i >= matrix.size() || j >= matrix[i].size())
            return 101; // return very high values when the j or i is going outside , for example in the example when 1->4 
            // now for 4 there are 3 options but one of teh option is invalid so we have to make it illegal
        if (i == matrix.size() - 1)
            return matrix[i][j];
        int less = matrix[i][j] + solve(i + 1, j - 1, matrix);
        int middle = matrix[i][j] + solve(i + 1, j, matrix);
        int more = matrix[i][j] + solve(i + 1, j + 1, matrix);
        return min(less, min(middle, more));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int min = INT_MAX;
        int minidx = 0;
        // calculates the mini element in the first row
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (matrix[0][i] < min)
            {
                min = matrix[0][i];
                minidx = i;
            }
        }
        return solve(0, minidx, matrix);
    }
};
// tle
class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> matrix)
    {
        if (i >= matrix.size() || j >= matrix[i].size())
            return 101; // return very high values when the j or i is going outside , for example in the example when 1->4 , now for 4 there are 3 options but one of teh option is invalid so we have to make it illegeal
        if (i == matrix.size() - 1)
            return matrix[i][j];
        int less = matrix[i][j] + solve(i + 1, j - 1, matrix);
        int middle = matrix[i][j] + solve(i + 1, j, matrix);
        int more = matrix[i][j] + solve(i + 1, j + 1, matrix);
        return min(less, min(middle, more));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // vector<vector<int>> d
        int min = INT_MAX;
        // int minidx=0;
        // calculates the mini element in the first row
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (solve(0, i, matrix) < min)
            {
                min = solve(0, i, matrix);
            }
        }
        return min;
    }
}; // we have to optimize this
// tle in memoized version also
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>matrix,vector<vector<int>>&dp)
    {
        if(i>=matrix.size() || j>=matrix[i].size())return 101; // return very high values when the j or i is going outside , for example in the example when 1->4 , now for 4 there are 3 options but one of teh option is invalid so we have to make it illegeal
        if(i==matrix.size()-1)return matrix[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int less = matrix[i][j] + solve(i+1,j-1,matrix,dp);
        int middle = matrix[i][j] + solve(i+1,j,matrix,dp);
        int more = matrix[i][j] + solve(i+1,j+1,matrix,dp);
        return dp[i][j]= min(less,min(middle,more));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int min=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<matrix[0].size();i++)
        {
            vector<vector<int>> dp(n,vector<int>(m,-1));
            if(solve(0,i,matrix,dp)<min)
            {
                min=solve(0,i,matrix,dp);
            }
        }
        return min;
    }
};
// no tle in tabular version 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // Initialize the first row of dp with the first row of matrix
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        // Fill the dp array
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i-1][j];
                int left = matrix[i][j];
                if (j - 1 >= 0) {
                    left += dp[i-1][j-1];
                } else {
                    left += 10001; // Large positive value
                }
                int right = matrix[i][j];
                if (j + 1 < m) {
                    right += dp[i-1][j+1];
                } else {
                    right += 10001; // Large positive value
                }
                dp[i][j] = min(up, min(left, right));
            }
        }
        // Find the minimum value in the last row of dp
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n-1][j]);
        }        
        return ans;
    }
};
