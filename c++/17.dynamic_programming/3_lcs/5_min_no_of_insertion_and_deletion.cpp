// return the minimum number of insertion and deletion that is to be made to change a to b
// suppose a:heap b:pea , heap->pea , insert 1 deletion 2,,
// if you look at it , deletions =  length(a) - lcs , insertions = length(b) - lcs

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
    string a = "heap";
    string b = "pea";
    int m = a.length();
    int n = b.length();
    // scs is geeke so expected answer 5
    cout<< "deletions:"<<m- lcs(a,b,m,n)<<" insertions:"<<n-lcs(a,b,m,n)<<endl;// expected 2 ,1 
return 0;
}
