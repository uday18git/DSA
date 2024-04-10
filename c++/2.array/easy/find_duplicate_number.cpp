// brute force solution
// sort it and linearly traverse and if i == i+1 element then we got our answer

// we can use hashing , map


// linked list approach

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

    
}