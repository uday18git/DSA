// if we use arrays then when we declare arr[100] and we enter only 10 elements the storage is wasted so we use linked list implementation for queues
#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class queue
{
    public:
    node* front;
    node* back;
    queue()
    {
        front = nullptr;
        back = nullptr;
    }
    void push(int x){
        node* n=new node(x);
        if(front == nullptr)
        {
            front =n;
            back = n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if(front == nullptr)
        {
            cout<<"queue underflow"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek()
    {
        if(front==nullptr){
            cout<<"no elements in the queue"<<endl;
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front == nullptr)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    q.pop();
    cout<<q.empty()<<endl;
    
    

}