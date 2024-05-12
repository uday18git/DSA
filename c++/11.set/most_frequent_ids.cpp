#define ll long long int
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        set<pair<ll,ll>,greater<pair<ll,ll>>> s;
        unordered_map<ll,ll>mp;
        vector<ll>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pair<ll,ll> p= {mp[nums[i]],nums[i]};
            if(s.find(p)!=s.end())
            {
                s.erase(p);
            }
            mp[nums[i]]+=freq[i];
            s.insert({mp[nums[i]],nums[i]});
            auto x = *s.begin();
            ans.push_back(x.first);
        }
        return ans;
    }
};