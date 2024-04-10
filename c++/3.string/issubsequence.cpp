class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int j = 0;
        int n = t.size();
        for (int i = 0; i < n; i++)
        {
            if (t[i] == s[j])
                j++;
        }
        return j == s.size();
    }
};