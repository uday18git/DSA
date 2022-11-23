#include<bits/stdc++.h>
//or #include<stack>
using namespace std;
void reverseSent(string s)
{
    stack<string> st;
    
    for(int i=0;i<s.length();i++)
    {
        string word = "";
        while(s[i] != ' ' && i<s.length())//' ' not " "
        {
            word+=s[i];
            i++;
        }
        st.push(word);

    }
    while(!st.empty()){
        //till stack is not empty the while loop will execute
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
int main()
{
    string s = "Hey how r u doing";
    reverseSent(s);
}