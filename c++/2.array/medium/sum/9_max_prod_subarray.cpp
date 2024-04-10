class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxprod=nums[0];
        int minprod=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp = maxprod; //important because the maxprod is being modified we need the old one only when computing the minprod also so...
            maxprod = max(nums[i],max(maxprod*nums[i],minprod*nums[i]));
            minprod = min(nums[i],min(minprod*nums[i],temp*nums[i]));
            ans=max(ans,maxprod);
        }
        return ans;
    }
};