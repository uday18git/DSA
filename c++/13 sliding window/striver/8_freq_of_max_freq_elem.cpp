// https://leetcode.com/problems/frequency-of-the-most-frequent-element/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=0;
        int res=0;
        long long total=0;
        while(r<n)
        {
            total+=nums[r];
            long long curr = (long long)nums[r]*(long long)(r-l+1);
            while(curr-total > k)
            {
                total-=nums[l];
                l++;
                curr = (long long)nums[r]*(r-l+1);
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};