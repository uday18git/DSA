#include <bits/stdc++.h>
using namespace std;
void gen(string op, int o, int c)
{
    if(o==0 && c==0)
    {
        cout<<op<<endl;
        return;
    }
    if(c>o)
    {
        gen(op+")",o,c-1);
    }
    if(o!=0)
    {
        gen(op+"(",o-1,c);
    }
}
int main()
{
    gen("", 3, 3);
    return 0;
}