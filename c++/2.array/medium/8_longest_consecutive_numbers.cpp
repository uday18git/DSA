#include <bits/stdc++.h>
using namespace std;
#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end()); // initializing with the nums
        int n=nums.size();
        if(n==0 || n==1)
        {
            return n;
        }
        int ans=1;
        for(int num:nums)
        {
            if(s.find(num-1)==s.end()) // selecting the number which doesnt have a prev element , this way we are starting from the least possible of that sequence and checking ..
            {
                int curr_count=1;
                while(s.find(num+1)!=s.end())
                {
                    curr_count++;
                    num++;
                }
                ans=max(ans,curr_count);
            }
        }
        return ans;
    }
};