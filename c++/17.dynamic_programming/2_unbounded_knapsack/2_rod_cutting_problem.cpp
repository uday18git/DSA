// rod cutting problem 
// is exactly unbounded knapsack but often used in interviews to check whether you identify the problem or not
// problem statement -> given a rod of length n and prices of all pieces smaller than n, find the optimal way to cut the rod into smaller rods in order to maximize the profit
// we can make any number of cuts and the length of each piece can be different, so it is an unbounded knapsack problem
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    // expected answer 22
    int L=8;
    int n = prices.size();
    vector<int> length;
    for(int i=0;i<n;i++)
    {
        length.push_back(i+1);
    }
    vector<vector<int>> dp(n+1,vector<int>(L+1,0));
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<L+1;j++)
        {
            if(length[i-1]<=j)
            {
                dp[i][j] = max(dp[i][j-length[i-1]]+prices[i-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][L]<<endl;

    return 0;

}

