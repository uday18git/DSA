#include <iostream>
#include <vector>
#include<string>
using namespace std;
bool isSafe(vector<vector<int>> &arr,int x,int y,int n)
{
    for(int i=0;i<x;i++)// to see if that columnnnn!! already there's a queen (above only)
    {
        if(arr[i][y]==1)
        {
            return false;
        }
    }
    int col=y;
    int row=x;
    while(row>=0 && col>=0)//left diagonal
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n)//right diagonal
    {
        if(arr[row][col]==1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}
bool nqueen(vector<vector<int>> &arr,int x,int n)
{
    if(x>=n)//base condition
    {
        return true;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafe(arr,x,col,n))
        {
            arr[x][col]=1;

            if(nqueen(arr,x+1,n))
            {
                return true;
            }
            arr[x][col]=0;//backtracking
        }
    }
    return false;
}
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> arr(n,vector<int>(n,0));
//     /*
//     We create a 2D vector containing "n"
//     elements each having the value "vector<int> (m, 0)".
//     "vector<int> (m, 0)" means a vector having "m"
//     elements each of value "0".
//     Here these elements are vectors.
//     */
//     // for(int i=0;i<n;i++)
//     // {
//     //     arr[i]=new int[n];
//     //     for(int j=0;j<n;j++){
//     //         arr[i][j]=0;
//     //     }
//     // }
//     if(nqueen(arr,0,n)){
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout<<arr[i][j]<<" ";
//             }cout<<endl;
//         }
//     }
//     return 0;
// }

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. n must be a positive integer." << endl;
        return 1;
    }

    vector<vector<int>> arr(n, vector<int>(n, 0));

    if (nqueen(arr, 0, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist for n = " << n << endl;
    }

    return 0;
}