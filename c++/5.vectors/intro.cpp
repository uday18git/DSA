#include<bits/stdc++.h> 
 
using namespace std;
int main(){
    int n,a;
    vector<int> v1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v1.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        cout<<v1[i]<<endl;
    }
return 0;
}