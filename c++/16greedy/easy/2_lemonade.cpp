class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        map<int, int> mp;
        int n = bills.size();

        for (int i = 0; i < n; i++)
        {

            if (bills[i] == 10)
            {
                if (mp.find(5) == mp.end())
                {
                    return false;
                }
                else
                {
                    mp[5]--;
                    if (mp[5] == 0)
                    {
                        mp.erase(5);
                    }
                }
            }
            else if (bills[i] == 20)
            {
                // if(!((mp[10]>=1 && mp[5]>=1) || mp[5]>=3))
                // {
                //     return false;
                // }
                if (mp[10] >= 1 && mp[5] >= 1)
                {
                    mp[10]--;
                    mp[5]--;
                    if (mp[10] == 0)
                    {
                        mp.erase(10);
                    }
                    if (mp[5] == 0)
                    {
                        mp.erase(5);
                    }
                }
                else if (mp[5] >= 3)
                {
                    mp[5] = mp[5] - 3;
                    if (mp[5] == 0)
                    {
                        mp.erase(5);
                    }
                }
                else
                {
                    return false;
                }
            }
            mp[bills[i]]++;
        }
        return true;
    }
};