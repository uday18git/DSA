#include <bits/stdc++.h>
using namespace std;
// stack inputted here is sorted , and we have to put temp in its appropriate place
// very similar to reverse
void insert(stack<int> &s,int temp)
{
    if(s.empty() || s.top()<=temp)
    {
        s.push(temp);
        return;
    }
    int t = s.top(); // stack is not empty so this is current highest element
    s.pop();
    insert(s,temp);  
    s.push(t); // when the above call returns (base condition occurs) that means its been sorted so we push back the highest element
}
void sort_stack(stack<int> &s)
{
    if(s.size()==1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sort_stack(s);
    insert(s,temp);

}
// delete middle element of a stack
// flow -> problem statement ip/op
// hypothesis , base condition , induction
void middle(stack<int> &s,int k)
{
    if(k==1)
    {
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    middle(s,k-1);
    s.push(temp);
    return;
}

// to reverse a stack using recursion
// void reverse(stack<int> &s,stack<int> &ans) //do not use extra space
// {
//     if(s.size()==0)
//     {
//         return;
//     }
//     int temp = s.top();
//     s.pop();
//     ans.push(temp);
//     reverse(s,ans);
//     return;

// }
void helper(stack<int>&s,int temp) // helper function puts the temp at the last of the stack
{
    if(s.size()==0)
    {
        s.push(temp);
        return;
    }
    int t=s.top();
    s.pop();
    helper(s,temp);
    s.push(t);
    return;
}
void reverse(stack<int>&s)// removes the top element and passes it to helper 
{
    if(s.size()==1)
    {
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    helper(s,temp);
    return;

}

int main()
{
    stack<int> s;
    s.push(100);
    s.push(99);
    s.push(98);
    s.push(97);
    s.push(96);
    s.push(95);
    // sort_stack(s);
    // int k = s.size()/2 +1;
    // middle(s,k);
    // stack<int> ans;
    // while(!s.empty())
    // {
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    // s.push(100);
    // s.push(99);
    // s.push(98);
    // s.push(197);
    // s.push(96);
    // s.push(95);
    // cout<<endl;
    // reverse(s,ans);

    // while(!ans.empty())
    // {
    //     cout<<ans.top()<<" ";
    //     ans.pop();
    // }
    reverse(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
   
    
}

