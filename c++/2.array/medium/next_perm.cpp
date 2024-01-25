// question is
// given [2 1 3] array 
// find the next permutation
// if you remove all the permutations of 
// [1 2 3]
// you have to give which comes next lexicographically to [2 1 3]
// start from the last and find the break point , where a[i]<a[i+1]
// so first step is to find the longest prefix 
// second step find element smallest element which is  > a[i] , then swap it with a[i]
// after that sort the rest of the array from a[i+1] to end

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // first find the break point
        int n=nums.size();
        int break_point=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break_point=i;
                break;
            }
        }
        if(break_point==-1)
        {
            sort(nums.begin(),nums.end());
            return;
            // return nums;
        }
        int sbp=nums[break_point+1];
        int sbpn = nums[break_point];
        int sbpi = break_point+1;
        for(int j=break_point+2;j<n;j++)
        {
            if(nums[j]<sbp && nums[j]>sbpn)
            {
                sbp=nums[j];
                sbpi=j;
            }
        }
        int temp = nums[break_point] ;
        nums[break_point] = nums[sbpi];
        nums[sbpi] = temp;
        sort(nums.begin()+break_point+1,nums.end());
        // return nums;



    }
};


// brute force approach is to generate all the possible permutations store it and perform linear search and return the next permutation
// takes n!*n time , very high tc

// better in stl there is a function next_permutation which will give off directly

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(),nums.end());
        
//     }
// };