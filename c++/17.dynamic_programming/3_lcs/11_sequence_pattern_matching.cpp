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
    string a = "AXY";
    string b = "ADXCPY";
    cout<<(lcs(a,b,a.length(),b.length())==a.length())<<endl;//expected 1

return 0;
}