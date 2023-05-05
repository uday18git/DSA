#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;
//
// int main()
// {
//     int n;cin>>n;
//     vector<int> v1(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>v1[i];
//     }
//     sort(v1.begin(),v1.end());
//     do{
//         ans.push_back(v1);
//     }while(next_permutation(v1.begin(),v1.end()));
//     for(int i=0;i<ans.size();i++)
//     {
//         for(int j=0;j<ans[i].size();j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// } 
void permute(vector<int>&a,int idx)
{
    if(idx==a.size())
    {
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++)
    {
        swap(a[i],a[idx]);
        permute(a,idx+1);
        swap(a[i],a[idx]);
    }
    return ;
}
int main()
{
    int n;cin>>n;
    vector<int> v1(n);
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    permute(v1,0);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
} 

//explain the above code
//