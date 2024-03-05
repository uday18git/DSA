#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<string> key = {"" , "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;

    void solve(string ip,string op)
    {
        if(ip.length()==0)
        {
            ans.push_back(op);
            return;
        }
        char ch = ip[0];
        string letters = key[ch-'0'];
        string ros = ip.substr(1);
        for(int i=0;i<letters.size();i++)
        {
            solve(ros,op+letters[i]);
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return {};
        }
        solve(digits,"");
        return ans;
    }
};

