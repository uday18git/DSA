// https://leetcode.com/problems/binary-subarrays-with-sum/
// same as subarray with sum k
//  but it is binary ,  no one will ask this
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
            if(sum<=goal) 
            {
                ans+=(r-l+1);
            }
            r++;
        }
        return ans;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int n1 = numSubarraysLessThanOrEqualToSum(nums,goal);
        int n2 = numSubarraysLessThanOrEqualToSum(nums,goal-1);
        return n1-n2;
        
    }
};



// count number of nice subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/



// we can reduce this problem to subarray sum  , by converting the numbers to 0 and 1 based on evne and odd
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int n=nums.size();
        int sum=0;
        int ans=0;
        // mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i]%2;
            if(sum==k) // same as doing mp[0]=1 and not writing this if statement
            {
                ans++;
            }
            
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};



// class Solution {
// public:
//     int numSubarraysLessThanOrEqualToSum(vector<int>nums,int goal)
//     {
//         if(goal<0)return 0;
//         int n=nums.size();
//         int l=0;
//         int r=0;
//         int sum=0;
//         int ans=0;
//         while(r<n)
//         {
//             sum+=(nums[r]%2);
//             while(sum>goal) // if it goes out of our goal , we have to make it inside first
//             {
//                 sum-=(nums[l]%2);
//                 l++;
//             }
//             if(sum<=goal) 
//             {
//                 ans+=(r-l+1);
//             }
//             r++;
//         }
//         return ans;
//     }
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n=nums.size();
//         int n1 = numSubarraysLessThanOrEqualToSum(nums,k);
//         int n2 = numSubarraysLessThanOrEqualToSum(nums,k-1);
//         return n1-n2;
//     }
// };


// your solution wont work buddy

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int l=0;
//         int r=0;
//         int n=nums.size();
//         int curr=0;
//         int ans=0;
//         while(r<n)
//         {
//             if(nums[r]%2==1)
//             {
//                 curr++;
//             }
//             while(curr>k)
//             {
//                 if(nums[l]%2==1)
//                 {
//                     curr--;
//                 }
//                 l++;
//             }
//             if(curr==k)
//             {
//                 ans++;
//             }
//             r++;
//         }
//         return ans;
//     }
// };

