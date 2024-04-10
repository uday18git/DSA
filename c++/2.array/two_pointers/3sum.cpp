class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int curr = nums[i];
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                if(nums[l] + nums[r] == -(curr))
                {
                    ans.push_back({nums[l],nums[r],curr});
                    while(l<r && nums[l] == nums[l+1])l++; // skipping same occurance of left
                    while(l<r && nums[r] == nums[r-1])r--; // same for right , else there will be repeating answers na
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] < (-curr))
                {
                    l++;
                }
                else
                {
                    r--;
                }

            }
        }
        return ans;
    }
};