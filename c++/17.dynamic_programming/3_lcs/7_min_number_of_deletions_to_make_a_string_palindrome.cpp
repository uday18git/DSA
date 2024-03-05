// answer = length(a) - lps(a)
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

int main(){
    string a = "agbcba";
    string t=a;
    reverse(a.begin(),a.end());
    string b=a;
    a=t;

    cout<<b.length() - lps(a,b,b.length(),b.length());// expected answer 2
return 0;
}