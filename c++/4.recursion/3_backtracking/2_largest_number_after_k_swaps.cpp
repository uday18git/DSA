// largest number after k_swaps
#include <bits/stdc++.h> 
using namespace std;

void solve(string &s,int k,string &ans,int start)
{
    if(k==0 || start== s.size()-1)
    {
        return;
    }
    char m = *max_element(s.begin()+start+1,s.end());
    for(int i=start+1;i<s.size();i++)
    {
        if(s[start]<s[i] && s[i]==m)
        {
            swap(s[start],s[i]);

            if(s.compare(ans)>0)
            {
                ans = s;
            }
            solve(s,k-1,ans,start+1);
            swap(s[start],s[i]);
        }
    }
    solve(s,k,ans,start+1); //horizontal drifting
}
int main(){
    string s = "1234567";
    int k=4;
    string ans=s;
    solve(s,k,ans,0);
    cout<<ans;
return 0;
}