#include <bits/stdc++.h> 
using namespace std;
// ab input
// output
// AB
// Ab
// aB
// ab
void permutation_case_change(string ip,string op)
{
    if(ip.size()==0)
    {
        cout<<op<<endl;
        return;
    }
    char t = toupper(ip[0]);
    string op1 = op + t; 
    string op2 = op+ip[0];
    string ros = ip.substr(1);
    permutation_case_change(ros,op1);
    permutation_case_change(ros,op2);
}

int main(){
    permutation_case_change("abc","");
return 0;
}