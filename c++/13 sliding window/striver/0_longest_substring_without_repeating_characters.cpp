// write down in  a sheet and work it down like a man 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r=0;
        int l=0;
        int n=s.size();
        int ans=0;
        map<char,int> mp;
        while(r<n)
        {
            if(mp.find(s[r])!=mp.end())
            {
                // l=mp[s[r]]+1; fails the case of abba , the left pointer comes till second b and right pointsr comes till a , then a has repeated so left pointer chagnes , but it changes wrong , so we have to take max of l,mp[s[r]]
                l =max(mp[s[r]]+1,l);
            }
            ans = max(ans,r-l+1);  
            mp[s[r]] =r;
            r++;
        }
        return ans;
    }
};