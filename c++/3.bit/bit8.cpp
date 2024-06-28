#include <bits/stdc++.h> 
using namespace std;

// 3191. Minimum Operations to Make Binary Array Elements Equal to One I
// we have to flip 3 consecutive elements to make the array all 1
// greedy works because we dont have any other choice , but to flip when we see a 0
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]==0)
            {
                ans++;
                for(int j=i;j<i+3;j++)
                {
                    nums[j]=!nums[j];
                }
            }
        }
        return (nums[n-1]==0 || nums[n-2]==0)?-1:ans;
    }
};

// 3292 
// we have to flip from i till end to make all the numbers in the array to 1
class Solution {
public:
    // we dont need to flip the array again and again , we just have to keep track how many times we flipped , if the number is a 1 and we flipped odd number of times till now then we have a 0 there so we will add to times and if we have a 0 currently and number of times we have flipped is even then we have to add to times because we have a 0

    int minOperations(vector<int>& nums) {
        int times=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if((nums[i]==0 && times%2==0) || (nums[i]==1 && times%2==1))
            {
                times++;
            }
        }
        return times;
    }
};


// 995. Minimum Number of K Consecutive Bit Flips
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flip(n, 0);  // This array will keep track of the flip operations
        int flipCount = 0;  // This keeps track of the current number of flips
        int result = 0;  // This will store the result

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flipCount -= flip[i - k];
            }
            // If the current bit is 0 and the flip count is even, we need to flip
            // If the current bit is 1 and the flip count is odd, we also need to flip
            if ((nums[i] == 0 && flipCount % 2 == 0) || (nums[i] == 1 && flipCount % 2 != 0)) {
                if (i + k > n) {
                    return -1;  // Not enough elements to flip
                }
                flip[i] = 1;
                flipCount++;
                result++;
            }
        }
        return result;
    }
};
