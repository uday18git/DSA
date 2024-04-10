class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int r = 0;
        int l = 0;
        int n = s.size();
        int maxLen = 0;
        map<char, int> mp;
        while (r < n)
        {
            if (mp.find(s[r]) != mp.end()) // this element exists in the map
            {
                l = max(mp[s[r]] + 1, l);
            }
            int len = r - l + 1;
            maxLen = max(len, maxLen);
            mp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};