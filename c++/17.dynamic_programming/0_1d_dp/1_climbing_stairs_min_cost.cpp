#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n=cost.size();
        for(int i=n-3; i>=0; i--)
        {
            cost[i]+= min(cost[i+1],cost[i+2]);
        }
        return min(cost[0],cost[1]);
    }
};


class Solution {
public:
    // passes 259 cases , plain recursion
    int solve(int i,int curr,vector<int>&cost)
    {
        if(i==cost.size())return curr;
        int one = solve(i+1,curr+cost[i],cost);
        if(i+2 <=cost.size())
        {
            int two = solve(i+2,curr+cost[i],cost);
            return min(one,two);
        }
        else
        {
            return one;
        }
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // cost[0], cost[1] we can start with these both
        return min(solve(0,0,cost),solve(1,0,cost));

    }
};

// memoization


class Solution{
    public:
        int minCostClimbingStairs(vector<int>&cost)
        {
            vector<int> memo(cost.size(),-1);
            return min(minCost(0,cost,memo),minCost(1,cost,memo));
        }
        int minCost(int i,vector<int>&cost,vector<int>&memo)
        {
            if(i>=cost.size())return 0;
            if(memo[i]!=-1)
            {
                return memo[i];
            }
            int one =  cost[i]  + minCost(i+1,cost,memo);
            int two = cost[i] + minCost(i+2,cost,memo);
            int minCostToTop= min(one,two);
            return memo[i] =minCostToTop;
        }
};
