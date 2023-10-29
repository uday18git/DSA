class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
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