#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
int main()
{
    int n;cin>>n;
    vector<int> v1;
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    sort(v1.begin(),v1.end());
    do{
        ans.push_back(v1);
    }while(next_permutation(v1.begin(),v1.end()));
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}