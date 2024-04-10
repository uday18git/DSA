class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target)return mid;
            // left sorted
            else if(nums[start]<=nums[mid])
            {
                // left is sorted and left has the target , so we eliminate right and search left
                if(nums[start]<=target && target<=nums[mid])
                {
                    end=mid-1;
                }
                // left is sorted but doesnt have the target , eliminate left so we search right
                else
                {
                    start=mid+1;
                }
            }
            // right sorted
            else if(nums[mid]<=nums[end])
            {
                // right is sorted and has the target , so we eliminate left and search right
                if(nums[mid]<=target && target<=nums[end])
                {
                    start=mid+1;
                }
                // right is sorted and doesnt have the target so we elminate right and search left
                else
                {
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};










//SEARCH IN SORTED AND ROTATED ARRAY
// arrray will be rotated from a pivot point
// search should be less than O(N)
// original array = [10,20,30,40,50]
// rotated array = [30,40,50,10,20]
// here pivot point is 50 and can be found out by arr[i]>arr[i+1]
// AFTER WE FIND OUT PIVOT POINT WE WILL JUST MAKE THE LEFT PART OF PIVOT THE LEFT HALF AND RIGHT HALF OF THE PIVOT THE RIGHT HALF
// THEN APPLY BINARY SEARCH IN BOTH LEFT AND RIGHT PARTS


// we check if the mid is in left sorted array or right sorted array
// then we check where the target is , according to that we will search there

// to find the minimum 
// see if we are in sorted portion, then compare with the left most element
// if we are not in sorted portion, we will do binary search, and if we are in left sorted array we know that the answer is in the right sorted array so we go there
// and if we are in the right sorted array we keep going to the left as the answer will be in left

#include <iostream>
#include <vector>
using namespace std;
int searchInRotatedSortedArray(vector<int> arr,int target)
{
    int left=0,right=arr.size()-1;
    while(left<=right)
    {
        int mid=(right+left)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[left]<=arr[mid])
        {
            if(arr[left]<=target && arr[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        else
        {
            if(target>arr[mid] && target<=arr[right])
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

    }
    return -1;
}



int main() {
    std::vector<int> rotatedArray = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = searchInRotatedSortedArray(rotatedArray, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
