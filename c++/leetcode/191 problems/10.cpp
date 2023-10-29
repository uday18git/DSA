// so many solutions
// sort it and iterate if any neighbour elements are equal break and print


// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int ans;
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 ans=nums[i];
//                 break;
//             }
//         }
//         return ans;
//     }
// };


// use map for linear

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         map<int,int> m;
//         int n=nums.size();
//         int ans;
//         for(int i=0;i<n;i++)
//         {
//             if(m[nums[i]]>0)
//             {
//                 ans= nums[i];
//                 break;
//             }
//             else
//             {
//                 m[nums[i]]++;
//             }
//         }
//         return ans;
//     }
// };


// linked list solution itseems
// uses slow and fast pointer
// int findDuplicate(vector < int > & nums) {
//   int slow = nums[0];
//   int fast = nums[0];
//   do {
//     slow = nums[slow];
//     fast = nums[nums[fast]];
//   } while (slow != fast);
//   fast = nums[0];
//   while (slow != fast) {
//     slow = nums[slow];
//     fast = nums[fast];
//   }
//   return slow;
// }

// can we do this with maths like expected sum and actual sum

// good soln but fails at [2,2,2,2,2]
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int ans=nums[0];
//         int n=nums.size();
//         for(int i=1;i<n;i++)
//         {
//             ans= ans^i^nums[i];
//         }
//         return ans;
//     }
// };