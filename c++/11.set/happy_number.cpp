class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> se;
        while (true)
        {
            string s = to_string(n);
            int len = s.size();
            int curr = 0;
            for (int i = 0; i < len; i++)
            {
                int num = s[i] - '0';
                curr += (num * num);
            }
            n = curr;
            if (se.find(curr) != se.end())
            {
                return false;
            }
            se.insert(curr);
            if (curr == 1)
            {
                return true;
            }
        }
        return false;
    }
};