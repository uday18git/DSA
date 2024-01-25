// example -> (1,3) (2,6) (8,9) (9,11) (8,10)
// (2,4) (15,18) (16,17)
// optimal approach 
// sort it 
// (1,3) (2,4) (2,6) (8,9) (8,10) (9,11)
// (15,18) (16,17)

// first start with 1,3
// then check if the next interval[0] is less than last intervals[1]
// if it is then ans.back[1] = next interval[1] 


// optimal approach is simpler than brute force lol


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;   
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=ans.back()[1])
            {
                if(ans.back()[1]<intervals[i][1])ans.back()[1] = intervals[i][1];
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};