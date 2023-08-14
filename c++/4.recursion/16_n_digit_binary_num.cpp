// print n bit binary numbers having more 1s than 0's for any prefix
// n is given in input
// - - - - - for each of these 0 or 1
#include <bits/stdc++.h>
using namespace std;
void nbit(int ones,int zeros,int n,string op)
{
    if(n==0)
    {
        cout<<op<<endl;
        return;
    }
    nbit(ones+1,zeros,n-1,op+'1');
    if(ones>zeros)
    {
        nbit(ones,zeros+1,n-1,op+'0');
    }
}
int main()
{
    nbit(0,0,3,"");
    return 0;
}