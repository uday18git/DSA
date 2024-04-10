#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        // question boils down to which is the longest substring with elements such that the elements other than max element has at most k frequency
        unordered_map<char,int>m;
        int l=0;
        int r=0;
        int currmax=0;
        int ans=0;
        while(r<s.length())
        {
            currmax=0;
            m[s[r]]++;
            for(auto it=m.begin();it!=m.end();++it) // finding the max element in the curr window
            {
                currmax = max(currmax,it->second);
            }
            if((r-l+1) - currmax <= k) // excluding max element there should be <=k elements
            {
                ans=max(ans,(r-l+1));
            }
            else
            {
                m[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;   
    }
};