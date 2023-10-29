// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         set<vector<int>>st;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 set<long long> hashset;
//                 for(int k=j+1;k<n;k++)
//                 {
//                     long long sum = nums[i]+nums[j];
//                     sum+=nums[k];
//                     long long fourth = target  - sum;
//                     if(hashset.find(fourth)!=hashset.end())
//                     {
//                         vector<int> temp={nums[i],nums[j],nums[k],int(fourth)};
//                         sort(temp.begin(),temp.end());
//                         st.insert(temp);
//                     }
//                     hashset.insert(nums[k]);
//                 }
//             }
//         }
//         vector<vector<int>>ans(st.begin(),st.end());
//         return ans;
//     }
// };
// very heavy but gets accepted

// brute force approach is to try out all the possible combinations
// to make it unique use set and shit, huge o(n^4), space complexity of set because to give unique values
 
// better solution is to use hashset