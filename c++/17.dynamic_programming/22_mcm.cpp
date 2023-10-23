// mcm recursive code
// if array size is 5 , there are 4 matrices
#include <bits/stdc++.h> 
using namespace std;

// int solve(vector<int>& arr, int i, int j) {
//     if (i >= j) { // = because array size of 1 is also invalid i/p 
//         return 0;
//     }
//     int minCost = INT_MAX;
//     for (int k = i; k < j; k++) {
//         int cost = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i-1] * arr[k] * arr[j];
//         minCost = min(minCost, cost);
//     }
//     return minCost;
// }

// int main() {
//     vector<int> arr = {40, 20, 30, 10, 30};
//     // 1 because matrix shape is [i-1] & [i]
//     cout << solve(arr, 1, arr.size() - 1) << endl;
//     return 0;
// }

// // mcm memoized

// int solve(vector<int> &arr,int i,int j,vector<vector<int>>&dp)
// {
//     if(i>=j)
//     {
//         return 0;
//     }
//     if(dp[i][j]!=-1)
//     {
//         return dp[i][j];
//     }
//     int minCost = INT_MAX;
//     for (int k = i; k < j; k++) {
//         int cost = solve(arr, i, k,dp) + solve(arr, k + 1, j,dp) + arr[i-1] * arr[k] * arr[j];
//         minCost = min(minCost, cost);
//     }
//     return dp[i][j]=minCost;

// }

// int main()
// {
//     vector<int> arr = {40, 20, 30, 10, 30};
//     int n=arr.size()-1;
//     vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
//     // we have to start with 1 because Ai = A[i-1]*A[i]
//     cout << solve(arr, 1, arr.size() - 1,dp) << endl;
//     return 0;
// }

