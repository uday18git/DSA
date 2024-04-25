// there are 2 ways u can implement this
// first 
// maintain 2 stacks
// enqueu .. push elements into the first stack
// dequeue .. if stack 2 is empty , push all elements of stack1 into stack2 , and pop the last element
// if not empty then normally pop

// another way is using function call stack
// if stack1 is empty then print error
// if stack1 has one element return it
// recursively pop everything from the stack1 ,
// store the popped item in a variable res, push the res back to stack1 and return res
#define vi vector<int>
#define si stack<int>
#include<bits/stdc++.h>
using namespace std;
class que{
    stack<int> s1;
    // stack<int> s2;
public:
    void push(int x)
    {
        s1.push(x);
    }
    // int pop(){
    //     if(s1.empty() and s2.empty())
    //     {
    //         cout<<"Queue is empty"<<endl;
    //         exit(0);
    //     }
    //     if(s2.empty())
    //     {
    //         while(!s1.empty())
    //         {
    //             s2.push(s1.top());
    //             s1.pop();
    //         }
            
    //     }
    //     int topval = s2.top();
    //     s2.pop();
    //     return topval;
    // }
    int pop()
    {
        if(s1.empty()){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;
        }
        int item = pop();
        s1.push(x);
        return item;
    }
    bool empty(){
        if(s1.empty()){
            cout<<"queue is empty"<<endl;
            return true;
        }
        return false;
    }
};
int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

}



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