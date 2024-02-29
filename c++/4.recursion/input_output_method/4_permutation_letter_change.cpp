// input a1B1
// op
// a1b1
// A1b1
// a1B1
// A1B1

#include <bits/stdc++.h> 
using namespace std;

void permutation_letter_change(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return ;
    }
    
    if(isdigit(ip[0]))
    {
        string ros = ip.substr(1);
        string op1 = op+ip[0];
        permutation_letter_change(ros,op1);
    }
    else
    {
        char u = toupper(ip[0]);
        char l = tolower(ip[0]);
        string op1 = op + l;
        string op2 = op + u;
        string ros = ip.substr(1);
        
        permutation_letter_change(ros,op1);
        permutation_letter_change(ros,op2);
    }
}

int main(){
    permutation_letter_change("a1B1","");
return 0;
}