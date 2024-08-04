#include <bits/stdc++.h>
using namespace std;
// string

void solve(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<" ";
        return; // v imp dont forget this
    }
    string op1 = op;
    string op2 = op+ip[0];
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);
}

void solve_ascii(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<" ";
        return; // v imp dont forget this

    }
    char ch = ip[0];
    int code = ch;
    string ros = ip.substr(1);
    string op1 = op;
    string op2 = op+ip[0];
    string op3 = op+ to_string(code);
    
    solve_ascii(ros,op1);
    solve_ascii(ros,op2);
    solve_ascii(ros,op3);
}

void solve_num(vector<int> ip, vector<int> op)
{
    if (ip.empty())
    {
        for (int num : op)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin());

    solve_num(ip, op2);
    solve_num(ip, op1);
}

int main()
{
    // solve("ab", "");
    solve_ascii("AB","");

    vector<int> input = {1, 2, 3};
    vector<int> output;

    // solve_num(input, output);

    return 0;
}




// VARIATIONS
// IF says no duplicates , then store it in set

// substrings with ascii codes