// approach make temp its first element will be always 1 and last element also
// fill in middle using the formula using observation , it will always be calculated from row above so [i-1] and then [j-1] and [j]


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)
        {
            return {{1}};
        }
        vector<vector<int>> ans={{1},{1,1}};
        for(int i=2;i<numRows;i++)
        {

            vector<int> temp(i);
            temp[0]=1;
            for(int j=1;j<i;j++)
            {
                temp[j] = ans[i-1][j-1]+ans[i-1][j];
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};