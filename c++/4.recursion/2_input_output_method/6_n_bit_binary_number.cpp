// n bit binary numbers with number of 1s greater than number of 0's is prefix

#include <bits/stdc++.h> 
using namespace std;

void n_bit(string op,int n,int o,int z)
{
    if(op.size()==n)
    {
        cout<<op<<endl;

        return;
    }
    string op1 = op + '0';
    string op2 = op + '1';
    if(o>z)
    {
        n_bit(op1,n,o,z+1);
    }
    n_bit(op2,n,o+1,z);
}

int main(){
    n_bit("",4,0,0);
return 0;
}