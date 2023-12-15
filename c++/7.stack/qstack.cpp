//Queue using stacks
#include <bits/stdc++.h> 
using namespace std;
class Queue
{
    stack<int>s1;
    stack<int>s2;
    public:
        // here we are implementing queues so we have to pop front and push back
        void push(int x)
        {
            s1.push(x);
        }
        int pop()
        {
            if(s1.empty() && s2.empty())
            {
                cout<<"The queue is empty cannot pop"<<endl;
                return -1;
            }
            else if(s2.empty()) // very nice
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                int topval=s2.top();
                s2.pop();
                return topval;

            }
        }
        bool empty()
        {
            if(s1.empty() && s2.empty())
            {
                return true;
            }
            else return false;
        }
}
int main(){

return 0;
}