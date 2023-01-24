#include<bits/stdc++.h>
using namespace std;
#define n 100
class Stack{
    int arr[n];
    int top;

    public:
    Stack(){
        
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
    


    cout<<st.Top()<<endl;
}
