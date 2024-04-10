// SAME QUESTION AS THE LAST ONE BUT WITH A LITTLE TWIST
// HERE WE CAN CONSIDER ODD NUMBERS AS 1 AND EVEN NUMBERS AS 0

class Solution
{
public:
    int numSubarraysLessThanOrEqualToSum(vector<int> nums, int goal)
    {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 0;
        while (r < n)
        {
            sum += (nums[r] % 2);
            while (sum > goal) // if it goes out of our goal , we have to make it inside first
            {
                sum -= (nums[l] % 2);
                l++;
            }
            if (sum <= goal)
            {
                ans += (r - l + 1);
            }
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int n1 = numSubarraysLessThanOrEqualToSum(nums, k);
        int n2 = numSubarraysLessThanOrEqualToSum(nums, k - 1);
        return n1 - n2;
    }
};

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
