
//crct answer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int start=0;
        char curr;
        int ans=0;
        for(int end=0;end<s.length();end++)
        {
            curr = s[end];
            if(m.find(curr)!=m.end())
            {
                start =max(start,m[curr]+1); // very important to take max of both!!!! 
                // if you dont take it will fail in test cases such as abba , 
                // because start will go off to 1st index and it will give wrong answers
            }
            m[curr]=end;
            ans = max(ans,end-start+1);
        }
        return ans;   
    }
};