#include <bits/stdc++.h>
using namespace std;

// logic here is keep popping elements until the stack is empty
// and insert , in the insert keep popping elements and insert at the last 

// or we can say like take the top element , reverse the rest of the stack and , put that top element into its right place
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

void insert1(stack<int> &s,int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert1(s,temp);
    s.push(val);
}
void rev(stack<int>&s)
{
    if(s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    rev(s);
    insert1(s,temp);
}


int main(){
    stack<int>s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(20);
    // rev(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}