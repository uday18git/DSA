// frog can jump 1 step or 2 steps at a time
// memoization solution
// partially accepted on coding ninjas
#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> heights, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);

    int right = INT_MAX;
    if (n > 1)
    {
        right = solve(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    return solve(n - 1, heights, dp);
}

// tabulation solution
// accepted on coding ninjas

#include <bits/stdc++.h>
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (i > 1)
        {
            dp[i] = min(dp[i - 1] + abs(heights[i - 1] - heights[i]), dp[i - 2] + abs(heights[i - 2] - heights[i]));
        }
        else
        {
            dp[i] = dp[i - 1] + abs(heights[i - 1] - heights[i]);
        }
    }
    return dp[n - 1];
}

// most optimal using space optimization 

int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}
