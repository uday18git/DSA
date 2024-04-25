// int * arr;
// arr = new int[5];
// dynamic memmory is allocated in heap
// static memory is allocated in stack
// code for static memory 
// int arr[5];
// code for dynamic memory
// int *arr;
// arr = new int[5];
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
        if(top==n-1)
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

// Stack class.
class Stack {
private:
    int * arr;
    int index;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        size = capacity;
        index=-1;
    }

    void push(int num) {
        // Write your code here.
        if(isFull())
        {
            return ;
        }
        index++;
        arr[index] = num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty())
        {
            return -1;
        }
        int temp = arr[index];
        index--;
        return temp;
    }
    
    int top() {
        // Write your code here.
        if(isEmpty())
        {
            return -1;
        }
        return arr[index];
    }
    
    int isEmpty() {
        // Write your code here.
        return index==-1;
    }
    
    int isFull() {
        // Write your code here.
        return index == size-1;
    }
    
};
