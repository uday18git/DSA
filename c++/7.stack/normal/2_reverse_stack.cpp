//REVERSE A STACK 
//easy  way is to use another stack but well not do that :(
#include<bits/stdc++.h>
using namespace std;
// The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. 
// think of it as 2 seperate functions 
// insertat bottome is removing all the elements and when the stack is empty it is putting our element into the stack
// and the reverse function will remove all the elements and when stack is empty it will start inserting the elements at the bottom 
// void insertAtBottom(stack<int> &st,int ele)
// {
//     if(st.empty())
//     {
//         st.push(ele);
//         return;
//     }
//     int topele = st.top();
//     st.pop();
//     insertAtBottom(st,ele);
//     st.push(topele);
// }


// void reverse(stack<int> &st){
//     if(st.empty()){
//         return;
//     }
//    //first we remove the top element and store it in ele.

//     int ele = st.top();
//     st.pop();
//     reverse(st);
//     insertAtBottom(st,ele);
// }
// int main()
// {
//     stack<int> st;
//     st.push(4);
//     st.push(3);
//     st.push(2);
//     st.push(1);
//     // reverse(st);
//     insertAtBottom(st,6);
    // for(int i=0;i<5;i++)
    // {
    //     int temp=st.top();
    //     st.pop();
    //     cout<<temp;
    // }
    // return 0;
// }
#include <bits/stdc++.h> 
using namespace std;
void insertAtBottom(stack<int>&st,int ele)
{
    if(st.empty())
    {
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele); // we have to still insert ele only at the bottom so we do this
    st.push(topele);
}
void reverse(stack<int>&st)
{
    if(st.size()==1)
    {
        return;
    }
    int ele=st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,ele);
}
// reverse will remove all the elements , and when stack is empty it will return
// then insert at bottom  
int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);
    for(int i=0;i<5;i++)
    {
        int temp=st.top();
        st.pop();
        cout<<temp;
    }
    return 0;
}