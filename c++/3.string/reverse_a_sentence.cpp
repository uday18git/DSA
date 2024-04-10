class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.length();
        string temp;
        string ans;
        for (int i = n - 1; i >= 0; i--)
        {
            while (i >= 0 && s[i] == ' ')
            { // skipping spaces
                i--;
            }
            while (i >= 0 && s[i] != ' ')
            { // putting non space into temp
                temp += s[i];
                i--;
            }
            if (!temp.empty())
            {
                reverse(temp.begin(), temp.end()); // if temp not empty , reversing and putting in answer
                ans += temp;
                ans += " ";
                temp = "";
            }
        }
        if (!ans.empty() && ans.back() == ' ')
        { // wen u add last word to the string it adds a extra space so remove that
            ans.pop_back();
        }
        return ans;
    }
};