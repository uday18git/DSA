// optimal solution is to flatten the matrix
// tc = O(log2(n*m))
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n=mat.size();
    int m=mat[0].size();
    
    int low=0,high= n*m-1,mid,row,col;
    while(low<=high)
    {
        mid= (high+low)/2;
        row=mid/m,col=mid%m;
        if(mat[row][col]==target)
        {
            return true;
        }
        else if(mat[row][col]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        
        
        
    }
    return false;
        
}



// bool searchMatrix(vector<vector<int>>& mat, int target) {
//     int i;
//     int n=mat.size();
//     int x=mat[0].size()-1;
//     for(i=0;i<n;i++)
//     {
       
//         if(mat[i][x]>target)
//         {
//             break;
//         }
//         else if(mat[i][x]==target)
//         {
//             return true;
//         }
        
//     }
//     if(i==n)
//     {
//         return false;
//     }
//     int high=x,low=0;
//     while(low<=high)
//     {
//         int mid=(high+low)/2;
//         if(mat[i][mid]==target)
//         {
//             return true;
//         }
//         else if(mat[i][mid]>target)
//         {
//             high=mid-1;
//         }
//         else
//         {
//             low=mid+1;
//         }
//     }
//     return false;
    
    
// }
// above solution is o(m + log(n)) where n is the size of each row and m is the number of rows



// brute force O(n*m)

// bool searchMatrix(vector<vector<int>>& mat, int target) {
//     int n=mat.size(),m=mat[0].size();
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(mat[i][j]==target)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }