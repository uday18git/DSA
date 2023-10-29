class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(m.count(target - nums[i]))
            {
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
            }
            m[nums[i]]=i;
        }  
        return ans;
    }
};


// brute force is to check all the combinations
// n^2

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int,int> m;
//         vector<int> ans;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(m.count(target-nums[i]))
//             {
//                 ans.push_back(i);
//                 ans.push_back(m[target-nums[i]]);
//                 break;
//             }
//             m[nums[i]]=i;
//         }
//         return ans;
//     }
// };

