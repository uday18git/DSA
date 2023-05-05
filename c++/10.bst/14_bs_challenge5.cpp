// Given an array of integers nums sorted in non-decreasing order,
// find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftMost(nums,target);
        int right = rightMost(nums,target); 
        if(left==-1)return {-1,-1};
        else return {left,right};
        
    }
    int leftMost(vector<int>&arr,int target)
    {
        int start = 0,end = arr.size()-1;
        int index=-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(arr[mid]>=target)
            {
                if(arr[mid]==target)
                {
                    index=mid;
                }
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return index;
    }
    int rightMost(vector<int>&arr,int target)
    {
        int start = 0,end = arr.size()-1;
        int index=-1;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(arr[mid]<=target)
            {
                if(arr[mid]==target)
                {
                    index=mid;
                }
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return index;
    }
};
// nums = [5,7,7,8,8,10], target = 8
//test case