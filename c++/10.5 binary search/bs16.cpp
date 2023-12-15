// there is a row wise and column wise sorted 2d array
// we have to search in it
// O(n square )approach 
// start in the top right corner and compare it with key and make adjustments and move
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{10,20,30,40},
    {15,25,35,45},{27,29,35,48},{32,33,39,50}};
    int m=arr[0].size()-1;
    int n=arr.size()-1;
    int i=0;
    int j=n;
    int key=0;
    while(i>=0 && j>=0 && i<=n && j<=m)
    {
        if(arr[i][j]==key)
        {
            cout<<"Found at"<<" "<<i+1<<" "<<j+1<<endl;
            break;
        }
        else if(arr[i][j]>key)
        {
            j--;
        }
        else 
        {
            i++;
        }
    }
    cout<<"Not found"<<endl;
    return 0;
}