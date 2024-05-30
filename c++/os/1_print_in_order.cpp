// we need that first -> printfirst() is executed -> T1 executes
// when first is printed -> T2 execute
// T2 has to wait for some condition which T1 will make true 
#include<bits/stdc++.h>
using namespace std;
#include<mutex>
#include<condition_variable>

class Foo {
    std::mutex m;
    std::condition_variable cv;
    int turn; // decides who's turn it is
public:
    Foo() {
        turn = 0;        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn=1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(m);
        while(turn!=1)
        {
            cv.wait(lock);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn=2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex>lock(m);
        while(turn!=2)
        {
            cv.wait(lock);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        
    }
};
int main()
{
    Foo ob = new Foo();
    

}