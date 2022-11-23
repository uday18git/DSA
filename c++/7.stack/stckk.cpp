#include<bits/stdc++.h>
using namespace std;
#define n 100
class Stack{
    int* arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if(top== n-1)
        {
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
        
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        top-- ;
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"no element"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top==-1;
    }

};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.pop();
    st.push(3);
    st.pop();
    st.pop();
    st.pop();

    cout<<st.Top()<<endl;
}
