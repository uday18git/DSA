// longest repeating subsequence 
// str = "AABEBCDD"
// answer ->3 (ABD) , because it is the longest subsequence with 2 occurances
#include <bits/stdc++.h> 
using namespace std;
int lcs(string x, string y,int n,int m)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(x[n-1]==y[m-1] && m!=n)
    {
        return 1+lcs(x,y,n-1,m-1);
    }
    else
    {
        return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}
int main(){
    string a = "AABEBCDD";
    cout<<lcs(a,a,a.length(),a.length())<<endl; // expected answer 3
return 0;
}
