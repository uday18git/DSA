// single element in a sorted array

// {1,1,2,2,3,3,4,5,5,6,6} => 4

// (even,odd) for the elements left to the single element
// (odd,even) for the elements right to the single element

// so for two same elements if the index is even odd then the single element is on the right side, eliminate the left side
// if the index is odd even then the single element is on the left side , eliminate the right side
// and also the single element is only element which is not equal to next and previous element
// suppose we are writing this above line condition, there are many edge cases to handle , so
// in binary search problems where many edge cases have to be handled , we have to remove / eliminate those (shrink the search space)
// take low=1, high=n-2
// so below i am checking for edge cases seperately and searching in the rest of the array
// f(arr,n)
// if(n==1)return arr[0];
// if(arr[0]!=arr[1])return arr[0];
// if(arr[n-1]!=arr[n-2])return arr[n-1];
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int start=1;
        int end=n-2;   
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1])return nums[mid];
            // if u r in the left half, ur either on the even index or odd index
            // element is in the right side, so we have to eliminate the left half
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]))
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return -1;
        
    }
};