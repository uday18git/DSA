// infix to postfix
// if operand print
// if '(' push to stack
// if ')' pop from stack and print until '(' is found
// if operator 

// pop from stack and print until an operator with less precedence is found
// consider this infix expression (a-b/c)*(a/k-l)
#include <bits/stdc++.h> 
using namespace std;
int prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixToPostfix(string s)
{
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) // if operand
        {
            res+=s[i];
        }
        else if(s[i] == '(') // if '('
        {
            st.push(s[i]);
        }
        else if(s[i] == ')') // if ')'
        {
            while(!st.empty() && st.top() != '(')
            {
                res+=st.top();
                st.pop();
            }
            if(!st.empty())
            { 
                st.pop(); // to remove '('
            }
        }
        else //operators
        {
            while(!st.empty() && prec(st.top()) > prec(s[i])) // if precedence of top element is greater than current element
            {
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }
    return res;
}

// for infix to prefix , reverse the string and interchange '(' and ')' and then call infixToPostfix function and then reverse the result , 
// logic is that precedence of operators will be reversed and associativity will be reversed so we will get the prefix expression.
string infixToPrefix(string s)
{
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(')
        {
            s[i] = ')';
        }
        else if(s[i] == ')')
        {
            s[i] = '(';
        }
    }
    string res = infixToPostfix(s);
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-l)"); // expected output: *-a/bc-/akl
    cout<<endl;
    cout<<infixToPostfix("(a-b/c)*(a/k-l)"); // expected output: abc/-ak/l-*
return 0;
}