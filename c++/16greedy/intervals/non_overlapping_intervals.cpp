// we have to find the minimum number of intervals to remove to make all the intervals non-overlapping
// first we need to sort it based on the start time
// then we need to iterate from left to right 
// we need to check if the current 2 intervals are overlapping 
// we will check that by intervals[i+1][0]> intervals[i][1] , so if the first interval ends before the second interval starts then they are not overlapping 
// if they are overlapping then we need to remove one of them , we remove the one which ends later , in this way we are minimizing the possibility of it overlapping with other intervals


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int count = 0;
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) {
                count++;
            } else {
                end = intervals[i][1];
            }
        }
        
        return count;
    }
};


// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& intervals) {
//         int count=0;
//         sort(intervals.begin(),intervals.end());
//         int n=intervals.size();
//         for(int i=0;i<intervals.size()-1;i++)
//         {
//             if(intervals[i][1]>intervals[i+1][0]) // overlapping
//             {
//                 if(intervals[i+1][1]>intervals[i][1])
//                 {
//                     intervals.erase(intervals.begin()+i+1);
//                     i--;
//                     count++;
//                 }
//                 else
//                 {
//                     intervals.erase(intervals.begin()+i);
//                     i--;
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
    
// };