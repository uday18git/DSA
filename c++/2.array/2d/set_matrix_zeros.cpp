// brute force approach only works for positive matrix values
// O(n^3)
// we are marking the row and column of the element 0 , with -1 then at last we are making all -1s 0
// so only works for +martix
// class Solution {
// public:
//     void markrow(vector<vector<int>>& matrix,int n,int m,int i)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j] && matrix[i][j]!=-1)
//             {
//                 matrix[i][j]=-1;
//             }
//         }
//     }
//     void markcol(vector<vector<int>>& matrix,int n,int m,int j)
//     {
//         for(int i=0;i<n;i++)
//         {
//             if(matrix[i][j] && matrix[i][j]!=-1)
//             {
//                 matrix[i][j]=-1;
//             }
//         }
//     }
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(!matrix[i][j])
//                 {
//                     markrow(matrix,n,m,i);
//                     markcol(matrix,n,m,j);
//                 }
//             }
//         }

//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==-1)
//                 {
//                     matrix[i][j]=0;
//                 }

//             }
//         }
        
//     }
// };

// more optimal approach
// firstly we will iterate through the array and mark row[i] and col[j]=1
// then in second iteration if the row[i] || col[j] is marked we mark it as 0


// time->O(n*m)
// space->o(n)
// uses extra space (2 arrays)

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<int> row(n,0);
//         vector<int> col(m,0);
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==0)
//                 {
//                     row[i]=1;
//                     col[j]=1;
//                 }
//             }
//         }
//         for(int i =0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(row[i]||col[j])
//                 {
//                     matrix[i][j]=0;
//                 }
//             }
//         }

//     }
// };


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j==0)
                    {
                        col0=0;
                    }
                    else
                    {
                        matrix[0][j]=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(col0==0)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][0]=0;
            }
        }
    }
};

