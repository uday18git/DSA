#include <bits/stdc++.h>
using namespace std;
void 1(string op, int o, int c)
{
    if(o==0 && c==0)
    {
        cout<<op<<endl;
        return;
    }
    if(c>o)
    {
        1(op+")",o,c-1);
    }
    if(o!=0)
    {
        1(op+"(",o-1,c);
    }
}
int main()
{
    1("", 3, 3);
    return 0;
}