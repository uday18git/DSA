class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)
        {
            return n;
        }
        unordered_set<int> s(nums.begin(),nums.end());
        
        int ans=1;
        for(int num:nums)
        {
            if(s.find(num-1)==s.end()) //nice , if we take s.find(num-1)!=s.end() then it will check again and again for the same sequence , but if we take num-1 , then one sequence will run only one time
            {
                int curlength=1;
                while(s.find(num+1)!=s.end())
                {
                    curlength++;
                    num++;
                }
                ans=max(ans,curlength);
            }
        }
        return ans;
        
    }
};
//nice