#include<iostream>
using namespace std;
//evaluate expression to true, we have to insert paranthesis so that it gives true and return number of ways we can do that
//there is | & ^ T F in our expressions


int solve(string s,int i,int j,bool isTrue)
{
    if(i>j)return true;
    if(i==j)
    {
        if(isTrue == true)return s[i]=='T';
        else return s[i]=='F';
    }
    int ans=0;

    for(int k=i+1;k<=j-1;k+=2)
    {
        int lT = solve(s,i,k-1,true);
        int lF = solve(s,i,k-1,false);
        int rT = solve(s,k+1,j,true);
        int rF = solve(s,k+1,j,false);
        if(s[k]=='&')
        {
            if(isTrue == true)
            {
                ans=ans+lT*rT;
            }
            else
            {
                ans =ans+(lT*rF) + (lF*rT) + (lF*rF);
            }
        }
        else if(s[k] == '|')
        {
            if(isTrue==true)
            {
                ans+= (lT*rF) + (lF*rT)+ (rT*lT);
            }
            else
            {
                ans=ans+lF*rF;
            }

        }
        else if(s[k] == '^')
        {
            if(isTrue==true)
            {
                ans=ans+(lT*rF) + (rF*rT)
            }
            else
            {
                ans=ans+(lT*rT) + (rF*lF);
            }
        }
        return ans;
    }
}
