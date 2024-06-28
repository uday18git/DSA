//============IMPLEMENTING STACK USING QUEUE==============//
//2 METHODS -- MAKING PUSH METHOD COSTLY , OR MAKING POP METHOD COSTLY
// Q1 AND Q2
//PUSH COSTLY
// !!!!!!!!!!!!
// THE POINT IN STACK USING Q IS THAT , WE ARE MAINTAINING STACK IN Q1 , 
// SO NEWLY ADDED ELEMENTS SHOULD BE IN THE FRONT OF Q1

// we are maintaining the stack in q1
// push
// 1. push the element in q2
// 2. push all the elements of q1 in q2
// 3. swap q1 and q2
// 4. increase the size of stack
// pop
// 1. pop the element from q1
// 2. decrease the size of stack
// 3. return the element
// so the point here is that in q only the front elemnt can be removed
// so q s front should be top of the stack so that we can remove it 
#include <bits/stdc++.h>
using namespace std;
// class Stack{
//     int N;
//     queue<int> q1;
//     queue<int> q2;
// public:
//     Stack(){
//         N=0;
//     }
//     void push(int val){
//         q2.push(val);
//         N++;
//         while(!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         queue<int> temp = q1;
//         q1=q2;
//         q2=temp;
//     }
//     void pop(){
//         q1.pop();
//         N--;
//     }
//     int top(){
//         return q1.front();
//     }
// };
// int main()
// {
//     Stack s1;
//     s1.push(1);
//     s1.push(2);
//     s1.push(3);
//     s1.push(4);
//     s1.pop();
//     cout<<s1.top()<<endl;
//     return 0;
// }

class Stack{
    private:
    queue<int> q1;
    queue<int> q2;
    public:
        int N;
        Stack()
        {
            N=0;
        }
        void push(int val)
        {
            q2.push(val);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> temp =q1;
            q1=q2;
            q2=temp;
            N++;
        }
        int pop()
        {
            int temp = q1.front();
            q1.pop();
            N--;
            return temp;
        }
        int top()
        {
            return q1.front();
        }

};
int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    cout<< s1.top()<<endl;
}