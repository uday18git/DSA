class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m)
        {
            return false;
        }
        vector<int> count(26);
        for(int i=0;i<n;i++)
        {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if(isPalindrome(count))
        {
            return true;
        }
        for(int i=n;i<m;i++)
        {
            count[s2[i] - 'a']--;
            count[s2[i-n]-'a']++;
            if(isPalindrome(count))
            {
                return true;
            }
        }
        return false;
    }
    bool isPalindrome(vector<int> count)
    {
        for(int i=0;i<count.size();i++)
        {
            if(count[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};