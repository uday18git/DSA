#include<iostream>
using namespace std;
//evaluate expression to true, we have to insert paranthesis so that it gives true and return number of ways we can do that
//there is | & ^ T F in our expressions
int solve(string s,int i,int j,int &ans)
{
    if(!(s.substr(i,j-i).compare("T")))
    {
        return 1;
    }
    if(!(s.substr(i,j-i).compare("F")))
    {
        return 0;
    }
    
    for(int k=i;k<j;k++)
    {
        bool result= solve(s,i,k,ans)||solve(s,k+1,j,ans);
        if(result)
        {
            ans++;
        } 
    }


}