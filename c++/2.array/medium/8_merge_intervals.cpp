// important , ans.back()
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans ;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=0;i<n-1;i++)
        {
            if(ans.back()[1]>=intervals[i+1][0] )
            {
                ans.back()[1]=max(intervals[i+1][1],ans.back()[1]);
            }
            else
            {
                ans.push_back(intervals[i+1]);
            }
        }
        return ans;
    }
};