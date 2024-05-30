#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    // more intuitive soln
    int majorityElement(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int candidate=nums[0];
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                candidate = nums[i];
                count++;
            }
            else if(nums[i] == candidate)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }
};
