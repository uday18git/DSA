#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
// we need the max subarray with same number of 0's and 1's , we will maintain a sum , and if sum==0 then check , 
// or if sum is 1 , or 2 , check for if that can be removed by checking in the map
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
            {
                sum++;
            }
            else
            {
                sum--;
            }
            if(sum==0)
            {
                ans=max(ans,i+1);
            }
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
            else
            {
                ans=max(i-mp[sum],ans);
            }
        }
        return ans;
    }
};