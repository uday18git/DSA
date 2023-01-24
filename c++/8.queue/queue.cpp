#include<iostream>
using namespace std;
//FIFO
//operations
//enqueue(x) pushhhh
//dequeue() poppppppppppp
//peek()
//empty

//=============== ARRAY IMPLEMENTATION =================
#define n 20
class queue{
    int* arr;
    int front;
    int back;
    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if(back == n-1)
        {
            cout<<"QUEUE OVERFLOW"<<endl;
            return;
        }
        else{
            back++;
            arr[back] = x;
            if(front == -1)
            {
                front++;
            }
        }    
    }
    void pop()
    {
        if(front == -1 || front>back)
        {
            cout<<"no elements"<<endl;
            return;
        }
        front++;
    }
    void peek(){
        if(front == -1 || front>back)
        {
            cout<<"no elements"<<endl;
            return;
        }
        else{
            cout<<arr[front]<<endl;
        }
    }
    bool empty()
    {
        if(front == -1 || front>back)
        {
            
            return true;
        }
        else{
            return false;
        }
    }
    void display()
    {
        if(front == -1 || front>back)
        {
            cout<<"no elements"<<endl;
            return;
        }
        else
        {
            for(int i=front;i<=back;i++)
            {
                cout<<arr[i]<<endl;
            }
        }
    }
};
int main()
{
    queue q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.peek();
    q.display();

    return 0;


}