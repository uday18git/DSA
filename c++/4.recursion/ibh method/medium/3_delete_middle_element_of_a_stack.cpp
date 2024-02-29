#include <bits/stdc++.h> 
using namespace std;
void solve(stack<int>&s, int k)
{
    if(k==1)
    {
        s.pop();
        return ;
    }
    int temp = s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);

}
stack<int> delMid (stack<int>&s)
{
    if(s.size()==0)
    {
        return s;
    }
    int t = int((s.size()-1)/2) + 1;
    solve(s,t);
    return s;
}

int main(){
    stack<int>s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(20);
    delMid(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}