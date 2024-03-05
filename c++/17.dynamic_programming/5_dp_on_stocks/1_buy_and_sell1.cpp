#include <bits/stdc++.h> 
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0;
        int ans = INT_MIN;
        if (prices.size() == 1)
            return 0;
        for (int r = 1; r < prices.size(); r++)
        {
            if (prices[r] < prices[l])
            {
                l = r;
            }
            ans = max(ans, prices[r] - prices[l]);
        }
        return ans;
    }
};