// GENERALLY IN THIS 1D DP 
// OUR BASE CASE WILL BE AT THE OPPOSITE END OF WHAT WE HAVE TO FIND 
// SOME TIMES WE MIGHT WANT TO FIND fn(0,BLA BLA) , THAT TIME THE BASE CASE WILL BE OF I==N
// AND WHEN WE ARE FINDING fn(n,bla bla) , that time the base case will be of i==0

// distinct ways to reach a nth step if we start from 0th step and can take 1 or 2 steps at a time
// how to understand that this is dp problem
// count the total number of ways or which is giving minimal and maximum output
// try all possible ways , best or count , thts when u try to apply recursion , all possible ways
// first think it is a recursive problem then dp
// try to represent the problem in terms of index
// do all possible stuffs on that index according tht problem
// sum of all stuffs -> count all ways
// find min -> take min of all stuff and same for max
// 0 1 2 3 4 5  ... ... n

// top down approach
// i tried writing base condition for i==n and stuff , but that dint work
// u have to take a simple base condition of whose output u know properly , for example the i==0 and i==1 u have , easily u can write
#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int solve(int i,vector<int>&dp)
    {
        if(i==0 || i==1)
        {
            return 1;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int one = solve(i-1,dp);
        int two = solve(i-2,dp);
        return dp[i] = one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};

// bottom up approach 
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1);
//         dp[0]=1;
//         dp[1]=1;
//         for(int i=2;i<=n;i++)
//         {
//             dp[i] = dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
// };


// time limit exceeded
// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n==1)return 1;
//         if(n==0)return 1;
//         int two = climbStairs(n-2);
//         int one = climbStairs(n-1);
        
//         return one+two;

//     }
// };