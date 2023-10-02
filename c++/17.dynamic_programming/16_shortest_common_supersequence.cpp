// we have to return the length of shortest common supersequence
#include <bits/stdc++.h> 
using namespace std;
int lcs(string x, string y,int n,int m)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(x[n-1]==y[m-1])
    {
        return 1+lcs(x,y,n-1,m-1);
    }
    else
    {
        return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
}
int main(){
    string a = "geek";
    string b = "eke";
    int m = a.length();
    int n = b.length();
    // scs is geeke so expected answer 5
    cout<< m+n - lcs(a,b,m,n)<<endl;
return 0;
}
