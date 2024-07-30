#include<bits/stdc++.h>
using namespace std;

class animal{
    public:
    
    virtual void bark() // if i remove virtual here , it will print super bark bark , else bark bark bark ...
    // this keyword tells to the compiler that hey maintain a vtable for this function... so that if it is over ridden... u can.. point to that
    {
        cout<<"super"<<endl;
    }
    static void b()
    {
        cout<<"lmao"<<endl;
    }
    
};
           // why public here what difference does it make
class dog : public animal{
    public:
        // over ride not neccessary but ..... simplyy
        void bark() override 
        {
            cout<<"bark"<<endl;
        }
};
int main()
{   
    dog* d = new dog();
    dog* d1 = new dog();
    animal* e1 = new dog();
    animal* a = new animal();
    a->b();
    e1->bark();
    d->bark();
    d1->bark();
    return 0;
}