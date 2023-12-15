//============IMPLEMENTING STACK USING QUEUE==============
//2 METHODS -- MAKING PUSH METHOD COSTLY , OR MAKING POP METHOD COSTLY
// Q1 AND Q2
//PUSH COSTLY
// we are maintaining the stack in q1
#include <bits/stdc++.h>
using namespace std;
class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
public:
    Stack(){
        N=0;

    }
    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }
    void pop(){
        q1.pop();
        N--;
    }
    int top(){
        return q1.front();
    }
};
int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    cout<<s1.top()<<endl;
    return 0;
}