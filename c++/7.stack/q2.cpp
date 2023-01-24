//REVERSE A STACK 
//easy  way is to use another stack but well not do that :(
#include<bits/stdc++.h>
using namespace std;
// The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, insert all held items one by one at the bottom of the stack. 
void insertAtBottom(stack<int> &st,int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}


void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    //first we remove the top element and store it in ele.

    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}
int main()
{
    
    return 0;
}