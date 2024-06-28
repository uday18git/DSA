// https://leetcode.com/problems/continuous-subarray-sum/ 
// here the property is used that sum%k if it repeats , then we have a subarray with that %k==0
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        int sum=0;
        // mp[sum%k]=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum%k==0 && i!=0)
            {
                return true;
            }
            if(mp.find(sum%k)!=mp.end() && (i-mp[sum%k])+1>2)
            {
                return true;
            }
            if(mp.find(sum%k)==mp.end())
            {
                mp[sum%k]=i;
            }
        }
        return false;
    }
};


// subarray sums divisble by k
// same as the above just it has negative numbers and they are asking count and not bool
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //sum%k number of occurances
        map<int,int> mp;
        int n=nums.size();
        int ans=0;
        int sum=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0) // your approach everything was correct , u just did not understand how -ve % +ve works
            {
                rem+=k;
            }
            ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
        // cout<<-1%2<<endl;
        // return 0;
    }
};