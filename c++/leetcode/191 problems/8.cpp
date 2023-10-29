class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++)
        {
            if(!ans.empty())
            {
                if(ans.back()[1]>=intervals[i][0])
                {
                    ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};

// first i tried to compare with the intervals [i][1] and intervals[i+1][0], which didnt work because we are not updating in the intervals arra
// so we have to compare with the ans array

// Time Complexity: O(N*logN) + O(N), where N = the size of the given array.
// Reason: Sorting the given array takes  O(N*logN) time complexity. Now, after that, we are just using a single loop that runs for N times. So, the time complexity will be O(N).
// Space Complexity: O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.