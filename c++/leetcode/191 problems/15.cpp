
// best soln
// moore's voting algorithm

// dry run
// [7 7 5 7 5 1 5 7]
// take 7 if its 7 then do count++ , if any other number then do minus, so till the end of the array if count >0 
//then it is the answer otherwise not, when count becomes 0 then we take a new element as the ans


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                ans=nums[i];
            }
            if(nums[i]==ans)
            {
                count++;
            }
            else
            {
                count--;
            }
        }        
        return ans;
    }
};







// better solution is to use hashmap or hasharray
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans(10000);
//         for(int i=0;i<n;i++)
//         {
//             ans[nums[i]]++;
//         }
//         int m=ans.size();
//         int a=-1;
//         for(int i=0;i<m;i++)
//         {
//             if(ans[i]>(n/2))
//             {
//                 a=i;
//             }
//         }
//         return a;
//     }
// };

// brute force is o(n^2)