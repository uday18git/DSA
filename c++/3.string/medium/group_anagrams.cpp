class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>> ans;
        for(string str:strs)
        {
            string temp = str;
            sort(str.begin(),str.end());
            mp[str].push_back(temp);
        }
        for(auto it :mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};