// here i did not consider that answer can come out of the non minimum element from the first row
#include <bits/stdc++.h>
using namespace std;
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
        // vector<vector<int>> d
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