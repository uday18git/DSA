// matrix questions we cannot optimize the time complexity more because we have to iterate no matter what so, we will try to optimize the space complexity, by using the given matrix itself
// time complexity O(2*(n*m))
//  space complexity O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int col0=1;
        // vector<int> row(n,0); ->matrix[..][0]
        // vector<int> col(m,0);-> matrix[0][..]
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(matrix[i][j]==0)
                    {
                        matrix[i][0]=0;
                        if(j!=0)
                        {
                            matrix[0][j]=0;
                        }
                        else
                        {
                            col0=0;
                        }
                    }
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]!=0)
                {
                    if(matrix[i][0]==0 || matrix[0][j]==0)
                    {
                        matrix[i][j]=0;
                    }
                
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(col0==0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }
    }
};



// more optimal approach

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




// brute force approach only works for positive matrix values
// O(n^3)
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