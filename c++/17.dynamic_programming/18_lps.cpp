// longest palindromic subsequence
// length of lps , nothing but lcs of a and reverse of a
#include <bits/stdc++.h> 
using namespace std;
int lps(string a,string b,int x,int y)
{
    if(!x || !y)
    {
        return 0;
    }
    if(a[x-1]==b[y-1])
    {
        return 1+lps(a,b,x-1,y-1);
    }
    else
    {
        return max(lps(a,b,x-1,y),lps(a,b,x,y-1));
    }
}
// same code as lcs so i did not write memoized and tabular
int main(){
    string a = "udaayaa";
    string t=a;
    reverse(a.begin(),a.end());
    string b=a;
    a=t;

    cout<<lps(a,b,b.length(),b.length()); // expected answer 5
return 0;
}
