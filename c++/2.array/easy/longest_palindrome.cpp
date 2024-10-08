// 409. Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        bool temp=false;
        int ans=0;
        map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        for(auto x = mp.begin();x!=mp.end();x++)
        {
            ans+=(x->second/2)*2; // odd freq will also go down to even freq
            if(x->second%2==1) // if any char is odd we can put a extra in middle so to indicate that maintain this variable
            {
                temp=true;
            }
        }
        if(temp)ans++;
        return ans;
    }
};