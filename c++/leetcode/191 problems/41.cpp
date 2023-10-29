class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return n;
        }
        
        int ans = 1; // The first element is always unique
        
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[ans] = nums[i]; // Overwrite duplicates
                ans++;
            }
        }
        
        return ans;
        
    }
};

//  nums.erase(nums.begin()+3) remove that element did not work

// nums.clear is to remove the whole array