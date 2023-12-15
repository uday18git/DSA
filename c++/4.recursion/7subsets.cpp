#include <bits/stdc++.h> 
using namespace std;
void solve(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<< op<<" ";
        return ;
    }
    string op1=op;
    string op2=op+ip[0];
    // op2.push_back(ip[0])
    ip.erase(ip.begin()+0);
    solve(ip,op2);
    solve(ip,op1);
}
int main(){
    solve("abc","");
return 0;
}



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

int main()
{
    vector<int> input = {1, 2, 3};
    vector<int> output;

    solve(input, output);

    return 0;
}


