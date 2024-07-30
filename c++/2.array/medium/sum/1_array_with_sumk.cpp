class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;// prefix sum -> number of occurances
        int n=nums.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)ans+=1;
            if(mp.find(sum-k)!=mp.end()) // IMPORTANT TO UNDERSTAND THE LOGIC OF SUM-K
            {
                // mp[k]+=mp[sum-k]; initial mistake was to put mp[k] in the map
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};