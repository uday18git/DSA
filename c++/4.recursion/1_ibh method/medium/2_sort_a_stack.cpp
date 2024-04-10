#include <bits/stdc++.h> 
using namespace std;

// LOGIC , same logic as sort the array using recursion , 
// take the top element of the stack and sort rest of the stack and insert the element in its right position in the sorted stack
void insert(stack<int>&s,int temp)
{
    if(s.size()==0 || s.top()<=temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}
void sort_stack(stack<int> &s)
{
    if(s.size()==1)
    {
        return ;
    }
    int t = s.top();
    s.pop();
    sort_stack(s);
    insert(s,t);
}



int main(){
    stack<int>s;
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(20);
    sort_stack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
return 0;
}