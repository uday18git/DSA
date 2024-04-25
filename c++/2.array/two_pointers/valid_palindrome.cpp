#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int r=n-1;
        int l=0;
        while(l<r)
        {
            while(l<r && !isalnum(s[l]))
            {
                ++l;
            }
            while(l<r && !isalnum(s[r]))
            {
                r--;
            }
            if(tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }
            --r;
            ++l;
        }
        return true;
    }
};
int main()
{
    Solution s;
    cout<<s.isPalindrome("i");
}