class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++) // j<i is important because , if we take j<n then two times it will swap and return to original position
            {
                swap(matrix[i][j],matrix[j][i]); // this is how you transpose in cpp
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


// brute force approach is to use another matrix and put rows as columns
// takes sc and tc of o(n^2) ,  but here it is not allowed

// so the optimal approach is to transpose and reverse each row
// takes no extra space