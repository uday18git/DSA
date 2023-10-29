// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int l=prices[0],r=prices[0],n=prices.size(),ans=INT_MIN;
//         for(int i=0;i<n;i++)
//         {
//             r=prices[i];
//             if(r<l)
//             {
//                 l=r;
//             }
//             ans=max(ans,r-l);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r=1,l=0;
        int ans=0;
        for(int r=1;r<prices.size();r++)
        {
            if(prices[l]<prices[r])
            {
                ans=max(ans,prices[r]-prices[l]);
            }
            else
            {
                l=r;
            }
        }
        return ans;
    }
};

