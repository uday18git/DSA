class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int rsum=0;
        int lsum=0;
        
        int n=cardPoints.size();
        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        int ans=lsum;// imp because this initial lsum was not getting considered below
        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--)
        {
            lsum-=cardPoints[i];
            rsum+=cardPoints[rightIndex];
            rightIndex--;
            ans=max(ans,lsum+rsum);
        }
        return ans;
    }
};
// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n=cardPoints.size();
//         int ans=0;
//         int r=n-1;
//         int l=0;
//         while(k>0 && r>=l)
//         {
//             if(cardPoints[r]>cardPoints[l])
//             {
//                 ans+=cardPoints[r];
//                 r--;
//                 k--;
//             }
//             else
//             {
//                 ans+=cardPoints[l];
//                 l++;
//                 k--;
//             }
//         }
//         return ans;
//     }
// };