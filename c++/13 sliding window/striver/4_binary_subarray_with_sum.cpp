class Solution {
public:
    int numSubarraysLessThanOrEqualToSum(vector<int>nums,int goal)
    {
        if(goal<0)return 0;
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int ans=0;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>goal) // if it goes out of our goal , we have to make it inside first
            {
                sum-=nums[l];
                l++;
            }
            if(sum<=goal) // if it is inside the goal , we can add the number of subarrays with sum less than or equal to goal
            {
                ans+=(r-l+1); // can verify this by observation
            }
            r++;
        }
        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int n1 = numSubarraysLessThanOrEqualToSum(nums,goal); // number of subarrays with sum less than or equal to goal
        int n2 = numSubarraysLessThanOrEqualToSum(nums,goal-1); // nuumber of subarrays with sum less than or equal to goal-1
        return n1-n2; //subtraction of both will give us the number of subarrays with sum equal to goal
        
    }
};