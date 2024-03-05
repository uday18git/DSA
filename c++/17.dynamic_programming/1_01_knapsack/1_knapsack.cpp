// Given an array of {weight,value} and a knapsack(bori) of a weight W. 
// Find the maximum value of items that can be stolen and put into knapsack
// Note -> we either have to pick the full item or (1) or no item
//  example -> Value -> {60,100,150}
// Weight -> {15,30,40}
//  W = 50
//  possible combinations -> {15,30} -> 160 {40}->150 
// {15,30} better answer
// we cannot apply greedy technique here because the items are indivisible meaning , items are either taken or not taken as a whole
// way of thinking
// we will iterate through the items array and we have two options for each array ->
// take it -> minus from W (capacity of the array)
// not take it -> capacity remains same
//  let f(n,w) = be the maximum value of items we can take till item n and current capacity of knapsack W
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
// just recursive code
int knapsack(int val[],vector<int> wt,int W,int n)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(wt[n-1]<=W)
    {
        return max(knapsack(val,wt,W-wt[n-1],n-1)+val[n-1],knapsack(val,wt,W,n-1));
    }
    else
    {
        return knapsack(val,wt,W,n-1);
    }
}
// main function for recursive code
int main(){
    vector<int> wt = {15,30,40};
    int val[] = {60,100,150};
    int W = 50;
    int n=wt.size();
    cout<<knapsack(val,wt,50,3)<<endl;
return 0;
}

// top down
// to memoize we can write a normal recursive code and memoize it
// to memoize means to store results of the expensive recursive calls and reuse them.
// to memoize it we will declare dp array


// this memoized version sometimes gives stack overflow error so tabulation is better in some cases
int knapsack(int wt[],int val[],int W,int n,vector<vector<int>>&dp) 
{
    if(n==0 || W==0)
    {
        return 0;
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(wt[n-1] > W)
    {
        return dp[n][W]=knapsack(wt,val,W,n-1,dp);
    }
    else
    {
        return dp[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1,dp),knapsack(wt,val,W,n-1,dp));
    }
}
//main function for memoization
// int main(){
//     int wt[] = {15,30,40};
//     int val[] = {60,100,150};
//     int W = 50;
//     int n=3;
//     vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
//     cout<<knapsack(wt,val,50,3,dp)<<endl;
// return 0;
// }

// using bottom up approach , tabulation
int main(){
    vector<int> wt = {15,30,40};
    int val[] = {60,100,150};
    int W = 50;
    int n=wt.size();
    // cout<<knapsack(wt,val,50,3)<<endl;
    vector<vector<int>> dp(n+1,vector<int>(W+1));
    for(int i=0;i<dp.size();i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<dp.size();i++)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<n+1;i++) // current number of items that we are taking
    {
        for(int j=1;j<W+1;j++) // current weight we are considering
        {
            if(wt[i-1]<=j)// wt[i-1] because we start frm 1 in the loop and in the table when we refer to 1 its the 1st item but in our array it starts with 0 indexing so
            {
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W]<<endl;
    

return 0;
}

