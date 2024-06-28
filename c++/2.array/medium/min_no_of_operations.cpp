// 945. Minimum Increment to Make Array Unique
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
// [1,1,2,2,3,7] ,  if nums[i] == nums[i-1]
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1])
            {   
                nums[i]++;
                ans++;
            }
            else if(nums[i]<nums[i-1])
            {
                ans+= (nums[i-1]-nums[i])+1;
                nums[i] = nums[i-1]+1;
            }
        }
        return ans;
    }
};


// [1,2,2]


