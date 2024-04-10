//optimal
// pointers for neg and pos 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int pos=0;
        int neg=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0){
                ans[neg] = nums[i];
                neg+=2;
                
            }
            else
            {
                ans[pos] = nums[i];
                pos+=2;
            }
        }
        return ans;
    }
};


// brute force approach
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int>ans,pos,neg;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]<0)neg.push_back(nums[i]);
//             else pos.push_back(nums[i]);
//         }
//         for(int i=0;i<nums.size()/2;i++)
//         {
//             ans.push_back(pos[i]);
//             ans.push_back(neg[i]);
//         }
//         return ans;
//     }
// };


// 2nd variety
// positive and negative are not equal
// you have to fallback to the brute force approach