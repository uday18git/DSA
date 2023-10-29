



// brute , just try out all the triplets
// o(n^3*log(number of unique triplets) time complexity
// space complexity 2*O(number of triplets)
// to give the unique values , we will sort all of the triplets and store it in set
// set<vector<int>> st;
// for(int i=0;i<n;i++)
// {
//     for(int j=i+1;j<n;j++)
//     {
//         for(int k=j+1;k<n;k++)
//         {
//             if(nums[i]+nums[j]+nums[k]==0)
//             {
//                 vector<int> temp = {nums[i]},nums[j],nums[k]};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//         }
//     }
// }
// vector<vector<int>> ans(st.begin(),st.end());
// return ans;
// will give time limit exceeded



// better solution

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
        
//         int n=nums.size();
//         set<vector<int>> st;
        
//         for(int i=0;i<n;i++)
//         {
//             set<int> hashset;
//             for(int j=i+1;j<n;j++)
//             {
//                 int third = -(nums[i]+nums[j]);
//                 if(hashset.find(third)!=hashset.end())
//                 {
//                     vector<int> temp={nums[i],nums[j],third};
//                     sort(temp.begin(),temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(nums[j]);
//             }

//         }
//         vector<vector<int>> ans(st.begin(),st.end());
//         return ans;
//     }
// };
// got tle for 2 test cases 
// tc = O(n^2 logn)


// we have to return unique solution
// optimal solution

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>>ans;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-2;i++)
//         {
//             int target=nums[i];
//             int l=i+1,r=nums.size()-1;
//             // i > 0: This condition checks if the current index i is greater than 0. It's there to avoid an "out of bounds" issue when comparing nums[i] with nums[i - 1].
//             // This block is used to skip duplicate elements in the nums array when considering the first element of the triplet (the element at index i).
//             if(i>0 && nums[i]==nums[i-1])  
//             {
//                 continue;
//             }
//             else
//             {
//                 while(l<r)
//                 {
//                     if(nums[l]+nums[r]==(-target))
//                     {
//                         ans.push_back({nums[i],nums[l],nums[r]});
//                         while (l < r && nums[l] == nums[l + 1]) l++; // Skip duplicates on the left.
//                         while (l < r && nums[r] == nums[r - 1]) r--; // Skip duplicates on the right.
//                         l++;
//                         r--;
//                     }
//                     else if(nums[l]+nums[r]<(-target))
//                     {
//                         l++;
//                     }
//                     else
//                     {
//                         r--;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

// sort the array
// then take one by one element , then remaining 2 elements will be there so the problem is reduced to 2 sum

















