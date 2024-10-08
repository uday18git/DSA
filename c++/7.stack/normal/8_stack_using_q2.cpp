//POP OPERATION COSTLY
//  SAME LOGIC  , RECENT ELEMENT SHOULD BE GIVEN WHEN POPPING
// push 
// we will just push into q1

// for pop
// pop all the elemnts from q1 except the last 1 , return that last one
// switch q1 and q2
#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q1;
    queue<int> q2;
    int N;
public:
    Stack(){
        N=0;
    }

    void push(int x)
    {
        N++;
        q1.push(x);
    }
    void pop()
    {
        if(q1.empty())
        {
            return;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> temp;
        temp=q1;
        q1=q2;
        q2=temp;
        N--;
    }
    int top()
    {
        return q1.back();
    }
};
int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    cout<<s1.top()<<endl;
    return 0;
}

