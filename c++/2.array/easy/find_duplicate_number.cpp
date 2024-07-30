// brute force solution
// sort it and linearly traverse and if i == i+1 element then we got our answer
// we can use hashing , map
// linked list approach
#include <bits/stdc++.h> 
using namespace std;
class Solution{
    public:
    int findDuplicate(int nums[])
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        // here they will reach a point in the circle where they will be x distance from the cycle starting 
        // then we move one of the pointer to the start then move one by one so we reach the common point 
        fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// we can do using xor also bro
class Solution {
public:
    int findDuplicatee(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            x=x^nums[i]^(i+1);
        }
        return x^(nums.size());
    }
};


int main(){
    Solution obj;
    int arr[] = {0,1,2,3,2};
    cout<<obj.findDuplicate(arr);
return 0;
}


// O(n) time complexity
// O(1) space