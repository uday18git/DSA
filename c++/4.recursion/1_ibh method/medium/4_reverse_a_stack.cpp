#include <bits/stdc++.h>
using namespace std;
void insert(stack<int>&s,int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}
void revStack(stack<int>&s)
{
    if(s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    revStack(s);
    insert(s,temp);
    
}
int main(){
    stack<int>s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(20);
    // revStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}