// https://leetcode.com/problems/majority-element/description/
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

// https://leetcode.com/problems/majority-element-ii/

// MAJORITY ELEMENT N/3

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,el1,el2;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && el2!=nums[i])
            {
                cnt1++;
                el1=nums[i];
            }
            else if(cnt2==0 && el1!=nums[i])
            {
                cnt2++;
                el2=nums[i];
            }
            else if(el1==nums[i])
            {
                cnt1++;
            }
            else if(el2==nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        // now that we have maintained that el1 and el2 are the highest occuring elements we will just count them 
        // again and if they are greater than n/3 we will push back it
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) cnt1++;
            if (nums[i] == el2) cnt2++;
        }
        vector<int> ans;
        if(cnt1> int(n/3)) ans.push_back(el1);
        if(cnt2 > int(n/3)) ans.push_back(el2);
        return ans;
    }
};