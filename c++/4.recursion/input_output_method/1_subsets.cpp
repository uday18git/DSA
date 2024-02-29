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
int main()
{
    solve("ab", "");
    return 0;
}
// numbers
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> ip, vector<int> op)
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

    solve(ip, op2);
    solve(ip, op1);
}

// int main()
// {
//     vector<int> input = {1, 2, 3};
//     vector<int> output;

//     solve(input, output);

//     return 0;
// }

// VARIATIONS
// IF says no duplicates , then store it in set