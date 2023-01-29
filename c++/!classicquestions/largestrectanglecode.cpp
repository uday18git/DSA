#include <bits/stdc++.h>
using namespace std;
//==========BRUTE FORCE===========//
int main(){
    int n,ans=0,a;
    vector<int> v1;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v1.push_back(a);
    }
    

    for(int i=0;i<n;i++)
    {
        int minh=v1[i];
        for(int j=i;j<n;j++)
        {
            minh = min(minh,v1[j]);
            int len = j-i+1;
            ans = max(ans,minh*len);
        }
    }
cout<<ans;

return 0;
}
//===================OPTIMISED=================//
