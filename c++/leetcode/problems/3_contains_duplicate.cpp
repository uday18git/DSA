// https://leetcode.com/problems/contains-duplicate/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]))
            {
                return true;
            }
            else
            {
                mp[nums[i]]=1;
            }
        }
        return false;   
    }
};

//  bool flag=false;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size()-1;i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 flag=true;
//                 break;
//             }
//         }
//         return flag;