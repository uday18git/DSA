// rotate in clockwise direction
// for each element at i,j
// it will go to j, n-1-i
// brute force approach
// brute force approach is to use another matrix and put rows as columns
// takes sc and tc of o(n^2) ,  but here it is not allowed
// brute force approach i,j will go to j,n-i-1
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<vector<int>> ans(n,vector<int>(m));
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 ans[j][n-1-i] = matrix[i][j];
//             }
//         }
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 matrix[i][j]=ans[i][j];
//             }
//         }
        
//     }
// };
// so the optimal approach is to transpose and reverse each row
// takes no extra space

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

// you can use unordered map
// and if map is not allowed, sort the array and then use two pointers