// sort an array of 0,1,2
// brute force approach is to use any sorting algorithm , like merge sort
// nlogn

// better solution is to count the 0s, 1s and 2s and fill it later

// optimal solution is Dutch national flag algorithm
// 3 ptrs  low,mid,high
// [0,low-1] will be 0
// [low,mid-1] will be 1
// [mid,high] will be unsorted 0,1,2 numbers , THAT MEANS THE ALGORITHM SHOULD RUN UNTIL MID REACHES HIGH (NO UNSORTED ELEMENTS REMAIN)
// [high+1,n-1] will be 2
// initially mid=0 and high=n-1 because all are unsorted

// so there are 3 possibilities
// if a[mid]=0 then swap(a[mid],a[low]) and increment mid and low , why increment low? because 0 till low-1 is 0
// if a[mid]=1 then increment mid
// if a[mid]=2 then swap(a[mid],a[high]) and decrement high
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};