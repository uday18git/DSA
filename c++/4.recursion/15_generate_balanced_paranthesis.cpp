#include <bits/stdc++.h>
using namespace std;
void generateBalancedParanthesis(string op, int o, int c)
{
    if(o==0 && c==0)
    {
        cout<<op<<endl;
        return;
    }
    if(c>o)
    {
        generateBalancedParanthesis(op+")",o,c-1);
    }
    if(o!=0)
    {
        generateBalancedParanthesis(op+"(",o-1,c);
    }
}
int main()
{
    generateBalancedParanthesis("", 3, 3);
    return 0;
}