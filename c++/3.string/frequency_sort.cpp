#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        vector<vector<char>> f(n+1);
        vector<int> cnt(128);
        for(char c:s) // stores the frequency of each character
        {
            cnt[c]++;
        }
        for(int i=0;i<128;i++)
        {
            f[cnt[i]].push_back(char(i));
        }
        string ans;
        for(int i = n;i>=0;i--)
        {
            for(char c:f[i])
            {
                ans+= string(i,c);
            }
        }
        return ans;


    }
};