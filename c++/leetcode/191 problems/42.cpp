class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                while(i<n && nums[i]==1 )
                {
                    curr++;
                    i++;
                }
                ans=max(curr,ans);

            }
            curr=0;
            
        }
        return ans;
    }
};