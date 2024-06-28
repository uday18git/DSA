// 3 sum closest
// naive approach , generate all the possible triplets and find the closest sum
// better approach is to sort the array and then use two pointer approach

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < closest)
                {
                    closest = abs(sum - target);
                    ans = sum;
                }
                if (sum < target)
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