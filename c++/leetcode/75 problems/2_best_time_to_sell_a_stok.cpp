// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r=1,l=0;
        int maxP=0;
        for(int r=1;r<prices.size();r++)
        {
            if(prices[l]<prices[r])
            {
                maxP= max(prices[r]-prices[l],maxP);
            }
            else
            {
                l=r;
            }
        }
        return maxP;
    }
};