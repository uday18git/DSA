class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            if(newInterval[1]<intervals[i][0]) // when new intervals is before the current interval
            {
                res.push_back(newInterval);
                while(i<n)
                {
                    res.push_back(intervals[i]);
                    i++;
                }
                return res;
            }
            else if(newInterval[0]>intervals[i][1]) // when new interval is after the current interval
            {
                res.push_back(intervals[i]);
            }
            else // when there is an overlap
            {
                newInterval = {min(newInterval[0],intervals[i][0]),max(newInterval[1],intervals[i][1])};
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

// flop attempt
// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int n=intervals.size();

//         for(int i=0;i<n;i++)
//         {
//             if(intervals[i][0] < newInterval[0] && intervals[i][1] > newInterval[1])
//             {
//                 return intervals;
//             }
//             else if(intervals[i][0] < newInterval[0])
//             {
//                 int prev=i;
//                 i++;
//                 while(i<n && intervals[i][1]< newInterval[1])
//                 {
//                     intervals.erase(intervals.begin() + i);
//                     i++;
//                 }
//                 if(i>=n)
//                 {
//                     intervals[n-1][1]=newInterval[1];
//                 }
//                 else
//                 {
//                     intervals[prev][1] = intervals[i][1];
//                     intervals.erase(intervals.begin()+i);
//                 }
//             }

//         }
//         return intervals;
//     }
// };