// https://leetcode.com/problems/two-sum/
#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(target-nums[i]))
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]]=i; // we add it later so that it does not take itself, both should be unique elements.
        }
        return ans;
    }
};


