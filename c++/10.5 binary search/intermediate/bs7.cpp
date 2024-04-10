// peak element
// we have to give index of peak element
// peak element means it should be greater than both its neighbours
// only one enough
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {5, 10, 20, 30, 10};
    int low = 0;
    int high = nums.size() - 1;
    int n = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid > 0 && mid < n)
        {
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                cout << mid;
                break;
            }
            else if (nums[mid] < nums[mid - 1])
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }
        else if (mid == 0)
        {
            if (nums[0] > nums[1])
            {
                cout << 0;
                break;
            }
            else
            {
                cout << 1;
                break;
            }
        }
        else if (mid == n)
        {
            if (nums[mid - 1] < nums[mid])
            {
                cout << mid << endl;
                break;
            }
            else
            {
                cout << mid - 1;
                break;
            }
        }
    }
    return 0;
}

// optimizing
// remember this enough
// passes 38/67 test cases
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n=nums.size();
//         // same logic(of handling edge cases) of the prev question
//         if(n==1)return 0;
//         if(nums[0]>nums[1])return 0;
//         if(nums[n-1]>nums[n-2])return n-1;
//         int start=1;
//         int end=n-2;
//         while(start<=end)
//         {
//             int mid = start+(end-start)/2;
//             if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;
//             else if(nums[mid]>nums[mid-1])start=mid+1;
//             else if(nums[mid]>nums[mid+1])end=mid-1;
//         }
//         return -1;
//     }
// };

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < nums[mid + 1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return start;
    }
};
